#pragma once
#include <iostream>
#include <memory>
#include "List.hpp"


template <typename T> class Queue {
private:
    List<T> queue;

public:
    T front() const  { return queue.front(); }
    template <typename U> void push( U &&n ) { queue.insert( std::forward<U>(n) ); }
    template <typename... Args> void emplace( Args &&...args ) {
        queue.insert( std::forward<Args>( args )... );
    }
    void pop() { queue.erase( 0 ); }
    size_t size() const { return queue.size(); }
    bool empty() { return queue.empty(); }
};
