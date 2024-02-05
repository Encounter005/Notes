#pragma once

#include "List.hpp"

template <typename T> class Queue {
public:
    Queue() = default;
    explicit Queue( const std::initializer_list<T> &items ) { list_( items ); }
    Queue( const Queue &other ) { *this = other; }
    Queue( Queue &&other ) { *this = std::move( other ); }
    ~Queue() = default;

    Queue &operator=( const Queue &other ) {
        if ( this != &other ) {
            this->list_ = other.list_;
        }
        return *this;
    }

    Queue &operator=( Queue &&other ) {
        if ( this != &other ) {
            Swap( other );
        }
        return *this;
    }

    void Swap( Queue &other ) {
        if ( this == &other ) {
            return;
        }
        this->list_.Swap( other.list_ );
    }

    void Push( const T &value ) { list_.Push_back( value ); }
    void Pop() { list_.Pop_front(); }

    template <typename... Args> void Emplace( Args &&...args ) {
        list_.Emplace_back( std::forward<Args>( args )... );
    }

    bool empty() const { return list_.empty(); }

    size_t size() const { return list_.size(); }

    T &front() const { return list_.Front(); }

private:
    List<T> list_;
};
