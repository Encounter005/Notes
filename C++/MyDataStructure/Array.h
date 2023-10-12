#pragma once

#include <iostream>
#include <cassert>
#include <memory>
#include <initializer_list>
#include <type_traits>
#include <cstddef>

template <typename T> class TD;

template <typename T> struct get_type {
    using type = T;
};

template <typename T> struct get_type<T *> {
    using type = T;
};

template <typename T> class Array {
public:
    Array( size_t size_ );
    Array( const std::initializer_list<T> &param );
    Array( std::initializer_list<T> &&param );
    Array( const Array &other );
    Array( Array &&other );
    ~Array();
    void Insert( size_t pos, T value );
    void Delete( size_t pos );
    T find( size_t pos );
    size_t cnt() const;
    T &begin() const;
    T &end() const;
    T &operator[]( size_t pos ) const;
    void clear();
    bool empty();

private:
    size_t size;
    std::unique_ptr<T[]> data;
};
