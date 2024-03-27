#pragma once

#include <stack>
#include <memory>
#include <mutex>
#include <exception>
#include <condition_variable>

struct StackEmpty : std::exception {
    const char *what() const throw();
};

template <typename T> class Stack_Thread_Safe {
public:
    Stack_Thread_Safe() = default;
    Stack_Thread_Safe( const Stack_Thread_Safe &other ) {
        std::lock_guard<std::mutex> lock_( mtx_ );
        stk_ = other.stk_;
    }
    Stack_Thread_Safe operator=( const Stack_Thread_Safe &other ) = delete;
    void push( T new_value ) {
        std::lock_guard<std::mutex> lock_( mtx_ );
        stk_.push( std::move( new_value ) );
        cv_.notify_one();
    }

    std::shared_ptr<T> wait_and_pop() {
        std::unique_lock<std::mutex> lock( mtx_ );
        cv_wait( lock, [this]() { return !stk_.empty(); } );

        std::shared_ptr<T> const res =
            std::make_shared<T>( std::move( stk_.top() ) );
        stk_.pop();
        return res;
    }

    bool try_pop( T &value ) {
        std::lock_guard<std::mutex> lock( mtx_ );
        if ( stk_.empty() ) {
            return false;
        }
        value = std::move( stk_.top() );
        stk_.pop();
        return true;
    }

    std::shared_ptr<T> try_pop() {
        std::lock_guard<std::mutex> lock( mtx_ );
        if ( stk_.empty() ) {
            return std::shared_ptr<T>();
        }

        std::shared_ptr<T> res(
            std::make_shared<T>( std::move( stk_.top() ) ) );
        stk_.pop();
        return res;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock_( mtx_ );
        return stk_.empty();
    }

private:
    mutable std::mutex mtx_;
    std::stack<T> stk_;
    std::condition_variable cv_;
};
