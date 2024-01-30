#pragma once

#include <iostream>
#include <future>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <vector>
#include <mutex>
#include <queue>
#include <functional>

template <typename T> class TD;

class ThreadPool {
public:
    ThreadPool( const ThreadPool & )            = delete;
    ThreadPool &operator=( const ThreadPool & ) = delete;

    static ThreadPool &getInstance() {
        static ThreadPool ins;
        return ins;
    }

    using Task = std::packaged_task<void()>;

    ~ThreadPool() { stop(); }

    // NOTE: 用于将任务队列中的任务提交到pool_里面
    template <typename F, class... Args>
    auto commit( F &&func, Args &&...args )
        -> std::future<decltype( func( args... ) )> {
        using RetType = decltype( func( args... ) );

        if ( stop_.load() ) {
            // NOTE: 这里如果触发异常处理，可以通过异常处理来了解状态
            return std::future<RetType>{};
        }

        // NOTE:关于这里为什么要使用std::shared_ptr
        // 1.
        // 避免对象过早的销毁，我们通常需要在另一个线程中执行task,可能会在创建的作用域之外。
        // 2.
        // 允许对象的共享，比如说，你可以在一个线程中安排一个任务，并在另一个线程中等待该任务完成并获取其结果。
        // 这样的话，任务对象就需要在多个线程中共享，而
        // std::shared_ptr 正好可以满足这个要求。
        auto task = std::make_shared<std::packaged_task<RetType()>>(
            std::bind( std::forward<F>( func ), std::forward<Args>( args )... ) );

        std::future<RetType> ret = task->get_future();
        {
            std::lock_guard<std::mutex> cv_mt( cv_mt_ );
            tasks_.emplace( [task] { ( *task )(); } );
        }
        cv_lock_.notify_one();
        return ret;
    }

    int idleThreadCount() { return thread_num_; }

private:
    ThreadPool( unsigned int num = 5 ) : stop_( false ) {
        if ( num < 1 ) {
            thread_num_ = 1;
        } else {
            thread_num_ = num;
        }
        start();
    }

    void start() {
        for ( int i = 0; i < thread_num_; i++ ) {
            pool_.emplace_back( [this]() {
                while ( !this->stop_.load() ) {
                    Task task;
                    std::unique_lock<std::mutex> cv_mt( cv_mt_ );
                    this->cv_lock_.wait( cv_mt, [this]() {
                        // NOTE:
                        // 当stop_为true,或者任务队列不空时，线程都会醒来。
                        return this->stop_.load() || !this->tasks_.empty();
                    } );

                    if ( this->tasks_.empty() ) {
                        return;
                    }

                    task = std::move( this->tasks_.front() );
                    this->tasks_.pop();
                    // 拿到一个任务，空闲线程-1
                    this->thread_num_--;
                    task(); // NOTE: 拿到一个新任务，进行异步调用，执行任务。
                    // 任务执行完之后，空闲线程又回来了，空闲线程+1
                    this->thread_num_++;
                }
            } );
        }
    }

    void stop() {
        stop_.store( true );
        cv_lock_.notify_all();
        for ( auto &td : pool_ ) {
            if ( td.joinable() ) {
                std::cout << "join thread " << td.get_id() << std::endl;
                td.join();
            }
        }
    }

private:
    std::mutex cv_mt_;
    std::condition_variable cv_lock_;
    std::atomic_bool stop_;
    std::atomic_int thread_num_;
    std::queue<Task> tasks_;
    std::vector<std::thread> pool_;
};
