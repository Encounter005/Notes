#pragma once

#include <iostream>
#include <queue>
#include <sstream>
#include <mutex>
#include <future>
#include <thread>
#include <condition_variable>
#include <any>

namespace AsyncLog {

enum LogLevel {
    DEBUGS  = 0,
    INFO    = 1,
    WARNING = 2,
    ERRORS  = 3,
};

// 要投递给队列的任务结构
class LogTask {
public:
    LogTask() = default;
    LogTask( const LogTask &other )
        : _level( other._level ), _logdatas( other._logdatas ) {}
    LogTask( LogTask &&other )
        : _level( other._level ), _logdatas( std::move( other._logdatas ) ) {}

    LogLevel _level;
    std::queue<std::any> _logdatas;
};

class AsyncLog {
public:
    static AsyncLog &getInstance() {
        static AsyncLog ins;
        return ins;
    }

    ~AsyncLog() {
        Stop();
        workthread_.join();
        std::cout << "exit success" << std::endl;
    }

    template <typename T> std::any toAny( const T &value ) {
        return std::any( value );
    }

    template <typename... Args>
    void AsyncWrite( LogLevel level, Args &&...args ) {
        auto task = std::make_shared<LogTask>();
        ( task->_logdatas.emplace( args ), ... );
        task->_level = level;
        std::unique_lock<std::mutex> lock( mtx_ );
        _queue.push( task );
        bool notify = ( _queue.size() == 1 ) ? true : false;
        lock.unlock();

        // 通知所有等待的线程有新的任务可以处理
        if ( notify ) {
            _empty_pond.notify_one();
        }
    }

    void Stop() {
        _b_stop = true;
        _empty_pond.notify_one();
    }

private:
    AsyncLog() : _b_stop( false ) {
        workthread_ = std::thread( [this]() {
            while ( true ) {
                std::unique_lock<std::mutex> lock( mtx_ );
                this->_empty_pond.wait( lock, [this]() {
                    return _b_stop || !this->_queue.empty();
                } );
                

                if ( _b_stop ) {
                    return;
                }

                auto logtask = _queue.front();
                _queue.pop();
                lock.unlock();
                processTask( logtask );
            }
        } );
    }

    AsyncLog &operator=( const AsyncLog & ) = delete;
    AsyncLog( const AsyncLog & )            = delete;

    bool convertToStr( const std::any &data, std::string &str ) {
        std::ostringstream ss;
        if ( data.type() == typeid( int ) ) {
            ss << std::any_cast<int>( data );
        } else if ( data.type() == typeid( float ) ) {
            ss << std::any_cast<float>( data );
        } else if ( data.type() == typeid( double ) ) {
            ss << std::any_cast<double>( data );
        } else if ( data.type() == typeid( std::string ) ) {
            ss << std::any_cast<std::string>( data );
        } else if ( data.type() == typeid( char * ) ) {
            ss << std::any_cast<char *>( data );
        } else if ( data.type() == typeid( char const * ) ) {
            ss << std::any_cast<char const *>( data );
        } else {
            return false;
        }
        str = ss.str();
        return true;
    }

    void processTask( std::shared_ptr<LogTask> logtask ) {
        std::cout << "Log level is: " << logtask->_level << std::endl;

        if ( logtask->_logdatas.empty() ) {
            return;
        }

        auto head = logtask->_logdatas.front();
        logtask->_logdatas.pop();

        std::string formatstr = "";
        bool bsuccess         = convertToStr( head, formatstr );
        if ( !bsuccess ) {
            return;
        }

        while ( !logtask->_logdatas.empty() ) {
            auto data = logtask->_logdatas.front();
            logtask->_logdatas.pop();
            formatstr = formatString( formatstr, data );
        }

        std::cout << "log string is " << formatstr << std::endl;
    }

    template <typename... Args>
    std::string formatString( std::string &format, Args... args ) {
        std::string result = format;
        size_t pos         = 0;

        // NOTE: 查找并替换字符串
        auto replacePlaceholder = [&]( const std::string &placeholder,
                                      const std::any &replacement ) {
            std::string str_replacement = "";
            bool bsuccess = convertToStr( replacement, str_replacement );
            if ( !bsuccess ) {
                return;
            }

            size_t placeholderPos = result.find( placeholder, pos );
            if ( placeholderPos != std::string::npos ) {
                result.replace(
                    placeholderPos, placeholder.length(), str_replacement );
                pos = placeholderPos + str_replacement.length();
            } else {
                result = result + " " + str_replacement;
            }
        };

        ( replacePlaceholder( "{}", args ), ... );
        return result;
    }

private:
    std::mutex mtx_;
    std::thread workthread_;
    std::condition_variable _empty_pond;
    std::queue<std::shared_ptr<LogTask>> _queue;
    bool _b_stop;
};

template <typename... Args> void ELog( Args &&...args ) {
    AsyncLog::getInstance().AsyncWrite( ERRORS, std::forward<Args>( args )... );
}

template <typename... Args> void DLog( Args &&...args ) {
    AsyncLog::getInstance().AsyncWrite( DEBUGS, std::forward<Args>( args )... );
}

template <typename... Args> void ILog( Args &&...args ) {
    AsyncLog::getInstance().AsyncWrite( INFO, std::forward<Args>( args )... );
}

template <typename... Args> void WLog( Args &&...args ) {
    AsyncLog::getInstance().AsyncWrite( WARNING, std::forward<Args>( args )... );
}

} // namespace AsyncLog
