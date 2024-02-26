#pragma once

#include <iostream>
#include <mutex>
#include <memory>

template <typename T, size_t MaxSize>
class CircularQueue : private std::allocator<T> {

public:
    CircularQueue()
        : max_size_( MaxSize + 1 ), head_( 0 ), tail_( 0 ),
          data_( std::allocator<T>::allocate( max_size_ ) ) {}

    CircularQueue( const CircularQueue & )                     = delete;
    CircularQueue &operator=( const CircularQueue & )          = delete;
    CircularQueue &operator=( const CircularQueue & ) volatile = delete;

    ~CircularQueue() {
        std::lock_guard<std::mutex> lock( mtx_ );
        while ( head_ != tail_ ) {
            std::allocator<T>::destroy( data_ + head_ );
            head_ = ( head_ + 1 ) % max_size_;
        }
        std::allocator<T>::deallocate( data_, max_size_ );
    }

    template <typename... Args> bool emplace( Args &&...args ) {
        std::lock_guard<std::mutex> lock( mtx_ );

        if ( ( tail_ + 1 ) % max_size_ == head_ ) {
            std::cout << "The Queue is full\n";
            return false;
        }

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
        head_ = ( head_ + 1 ) % max_size_;
        return true;
    }

private:
    T *data_;
    size_t head_;
    size_t tail_;
    std::mutex mtx_;
    size_t max_size_;
};
