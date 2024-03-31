#pragma once

#include <condition_variable>
#include <iostream>
#include <queue>
#include <mutex>
#include <vector>
#include <future>
#include <functional>
#include <thread>
#include <atomic>
#include "NonCopy.hpp"

class ThreadPool : public NonCopy {
public:
    static ThreadPool &getInstance() {
        static ThreadPool ins;
        return ins;
    }

    using Task = std::packaged_task<void()>;

    int threadCount() { return thread_num_; }

    ~ThreadPool() { stop(); }

    template <typename F, typename... Args>
    auto commit( F &&func, Args &&...args )
        -> std::future<decltype( func( args... ) )> {
        using RetType = decltype( func( args... ) );

        if ( stop_.load() ) {
            return std::future<RetType>{};
        }

        auto task = std::make_shared<std::packaged_task<RetType()>>( std::bind(
            std::forward<F>( func ), std::forward<Args>( args )... ) );
        std::future<RetType> ret = task->get_future();
        {
            std::lock_guard<std::mutex> lock( cv_lock_ );
            tasks_.emplace( [task]() { ( *task )(); } );
        }

        cv_var_.notify_one();
        return ret;
    }

private:
    ThreadPool( std::size_t num = std::thread::hardware_concurrency() ) {
        if ( num < 1 ) {
            num = 2;
        } else {
            thread_num_ = num;
        }
        start();
    }

    void start() {
        for ( int i = 0; i < thread_num_; i++ ) {
            pools_.emplace_back( [this]() {
                while ( !this->stop_.load() ) {
                    Task task;
                    std::unique_lock<std::mutex> lock( cv_lock_ );
                    this->cv_var_.wait( lock, [this]() {
                        return this->stop_.load() || !this->tasks_.empty();
                    } );

                    if ( this->tasks_.empty() ) {
                        return;
                    }

                    task = std::move( tasks_.front() );
                    tasks_.pop();
                    thread_num_--;
                    task();
                    thread_num_++;
                }
            } );
        }
    }

    void stop() {
        stop_.store( true );
        cv_var_.notify_all();
        for ( auto &t : pools_ ) {
            if ( t.joinable() ) {
                std::cout << "join thread " << t.get_id() << std::endl;
                t.join();
            }
        }
    }

private:
    std::mutex cv_lock_;
    std::condition_variable cv_var_;
    std::atomic_bool stop_;
    std::atomic_int thread_num_;
    std::queue<Task> tasks_;
    std::vector<std::thread> pools_;
};
