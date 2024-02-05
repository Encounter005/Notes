#pragma once

#include "List.hpp"

template <typename T> class Stack {
public:
    Stack() = default;
    explicit Stack( const std::initializer_list<T> &items ) { list_( items ); }
    Stack( const Stack &other ) { *this = other; }
    Stack( Stack &&other ) { *this = std::move( other ); }

    Stack &operator=( const Stack &other ) {
        if ( this != &other ) {
            this->list_ = other.list_;
        }
        return *this;
    }

    Stack &operator=( Stack &&other ) {
        if ( this != &other ) {
            this->list_.Swap( other.list_ );
        }
        return *this;
    }

    bool empty() const { return list_.empty(); }

    size_t size() const { return list_.size(); }

    void Push( const T &value ) { list_.Push_back( value ); }

    void Pop() { list_.Pop_back(); }

    template <typename... Args> void Emplace( Args &&...args ) {
        list_.Emplace_back( std::forward<Args>( args )... );
    }

    void Swap( Stack &other ) {
        if ( this == &other ) return;
        this->list_.Swap( other.list_ );
    }

    T& top() const {
        return list_.Back();
    }

private:
    List<T> list_;
};
