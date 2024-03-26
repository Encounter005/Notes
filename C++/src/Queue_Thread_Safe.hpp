#pragma once

#include <memory>
#include <mutex>
#include <condition_variable>
#include <queue>

template <typename T> class Queue_Thread_Safe {
private:
    std::queue<T> data_;
    std::mutex mtx_;
    std::condition_variable cvq_;

public:
    Queue_Thread_Safe() = default;
    Queue_Thread_Safe( const Queue_Thread_Safe & );
    void push( T && );
    void wait_and_pop( T && );
    std::shared_ptr<T> wait_and_pop();
    bool try_pop( T& );
    std::shared_ptr<T> try_pop();
    bool empty();
};

template <typename T>
Queue_Thread_Safe<T>::Queue_Thread_Safe( const Queue_Thread_Safe &other ) {
    std::lock_guard<std::mutex> lock( other.mtx_ );
    this->data_ = other.data_;
}

template <typename T> void Queue_Thread_Safe<T>::push( T &&param ) {
    std::lock_guard<std::mutex> lock( mtx_ );
    data_.emplace( param );
    // NOTE: 这里通知线程是因为如果别的线程有pop操作，由于队列可能是空的会被挂起，所以要通知一个线程
    cvq_.notify_one();
}

template <typename T> void Queue_Thread_Safe<T>::wait_and_pop( T &&value ) {
    std::unique_lock<std::mutex> lock( mtx_ );
    cvq_.wait( lock, [this]() { return !data_.empty(); } );
    value = data_.front();
    data_.pop();
}

template <typename T> std::shared_ptr<T> Queue_Thread_Safe<T>::wait_and_pop() {
    std::unique_lock<std::mutex> lock( mtx_ );
    cvq_.wait( lock, [this]() { return !data_.empty(); } );
    std::shared_ptr<T> res( std::make_shared<T>( data_.front() ) );
    data_.pop();
    return res;
}

template<typename T> bool Queue_Thread_Safe<T>::try_pop(T& value) {
    std::unique_lock<std::mutex> lock(mtx_);
    if(empty()) {
        return false;
    }
    value = data_.front();
    return true;
}

template<typename T>
std::shared_ptr<T> Queue_Thread_Safe<T>::try_pop() {
    std::unique_lock<std::mutex> lock(mtx_);
    cvq_.wait(lock, [this](){
        return !data_.empty();
    });
    std::shared_ptr<T> res( std::make_shared<T>(data_.front()) );
    data_.pop();
    return res;
}


template<typename T> bool Queue_Thread_Safe<T>::empty() {
    // WARN:这里记得要加个锁，因为在判断队列是否为空的时候，要保证状态一致
    std::unique_lock<std::mutex> lock(mtx_);
    return data_.empty();
}
