#pragma once

#include <iostream>
#include <memory>
#include "List.hpp"

template <typename T> class Stack {
private:
    List<T> stk;

public:
    T top() const { return stk.back(); }
    template <typename U> void push( U &&n ) { stk.insert( std::forward<U>(n) ); }
    void pop() { stk.erase( stk.size() - 1 ); }
    template <typename... Args> void emplace( Args &&...args ) {
        stk.insert( std::forward<Args>( args )... );
    }
    size_t size() { return stk.size(); }
    bool empty() { return stk.size(); }
};
