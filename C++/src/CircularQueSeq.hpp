
#pragma once

#include <iostream>
#include <mutex>
#include <memory>
#include <atomic>

template <typename T, size_t MaxSize>
class CircularQueue : private std::allocator<T> {

public:
    CircularQueue()
        : max_size_( MaxSize + 1 ), head_( 0 ), tail_( 0 ), _atomic_using(false) ,
          data_( std::allocator<T>::allocate( max_size_ ) ) {}

    CircularQueue( const CircularQueue & )                     = delete;
    CircularQueue &operator=( const CircularQueue & )          = delete;
    CircularQueue &operator=( const CircularQueue & ) volatile = delete;

    ~CircularQueue() {
        // 循环销毁
        bool use_expected = false;
        bool use_desire = true;

        do {
            use_expected = false;
            use_desire = true;
        } while(!_atomic_using.compare_exchange_strong(use_expected , use_desire));

        while ( head_ != tail_ ) {
            std::allocator<T>::destroy( data_ + head_ );
            head_ = ( head_ + 1 ) % max_size_;
        }
        std::allocator<T>::deallocate( data_, max_size_ );

        do {
            use_expected = true;
            use_desire = false;
        } while(!_atomic_using.compare_exchange_strong(use_expected , use_desire));
    }

    template <typename... Args> bool emplace( Args &&...args ) {
        std::lock_guard<std::mutex> lock( mtx_ );

        // NOTE: 判断队列是否满了
        if ( ( tail_ + 1 ) % max_size_ == head_ ) {
            std::cout << "The Queue is full\n";
            return false;
        }
        
        // NOTE: 如果队列没有满，就直接插入新的元素
        std::allocator<T>::construct(
            data_ + tail_, std::forward<Args>( args )... );
        tail_ = ( tail_ + 1 ) % max_size_;
        return true;
    }

    bool push( const T &param ) {
        std::cout << "call push const T& version\n";
        return emplace( param );
    }

    bool push( T &&param ) {
        std::cout << "call push T&& version\n";
        return emplace( std::move( param ) );
    }

    bool pop( T &param ) {
        std::lock_guard<std::mutex> lock( mtx_ );
        
        if ( head_ == tail_ ) {
            std::cout << "the queue is clear\n";
            return false;
        }
        
        param = std::move( data_[head_] );
        // NOTE: 删除的时候，只需要将head_指针向后移动即可
        head_ = ( head_ + 1 ) % max_size_;
        return true;
    }

private:
    T *data_;
    size_t head_;
    size_t tail_;
    std::atomic<bool> _atomic_using;
    size_t max_size_;
};
