#pragma once

#include <iostream>
#include <memory>
#include <array>
#include <algorithm>
#include <stdexcept>
#include <initializer_list>

template <typename T, size_t SIZE = 0> class Array {
public:
    Array() {
        num_items = SIZE;
        if ( num_items ) {
            data_ = std::unique_ptr<T[]>( new T[num_items] );
        } else {
            data_ = nullptr;
        }
    }

    Array( const std::initializer_list<T> &ilist ) {
        num_items = ilist.size();
        if ( ilist.size() ) {
            size_t idx = 0;
            data_      = std::unique_ptr<T[]>( new T[num_items]() );
            for ( auto &elm : ilist ) {
                data_[idx++] = elm;
            }
        } else {
            data_ = nullptr;
        }
    }

    Array( const Array &other ) {
        num_items = other.num_items;
        data_     = std::unique_ptr<T[]>( new T[num_items]() );
        std::copy( other.begin(), other.end(), this->data_.get() );
    }

    Array &operator=( const Array &other ) {
        if ( this == &other ) {
            return *this;
        }

        if ( !this->empty() ) {
            clear();
        }

        num_items = other.num_items;
        data_     = std::unique_ptr( new T[num_items]() );
        std::copy( other.begin(), other.end(), this->data_.get() );
    }

    ~Array() { clear(); }

    template <typename U> void Insert( U &&element ) {
        std::unique_ptr<T[]> new_data_( new T[num_items + 1]() );
        for ( size_t i = 0; i < num_items; i++ ) {
            new_data_[i] = data_[i];
        }
        new_data_[num_items] = element;
        num_items++;
        data_ = std::move( new_data_ );
    }

    template <typename U> void Insert( U &&element, size_t pos ) {
        try {
            if ( pos >= num_items ) {
                throw std::runtime_error( "The index is larger than the size" );
            }

            std::unique_ptr<T[]> new_data_( new T[num_items + 1]() );
            for ( size_t i = 0, j = 0; i < num_items; i++, j++ ) {
                if ( i == pos ) {
                    new_data_[j++] = element;
                    new_data_[j]   = data_[i];
                } else {
                    new_data_[j] = data_[i];
                }
            }

            data_ = std::move( new_data_ );
            num_items++;
        } catch ( const std::exception &e ) {
            std::cout << e.what() << std::endl;
        }
    }

    void Delete( size_t pos ) {
        if ( empty() ) {
            return;
        }
        std::unique_ptr<T[]> new_data_( new T[num_items - 1]() );
        for ( size_t i = 0, j = 0; i < num_items; i++, j++ ) {
            if ( i == pos ) {
                j--;
                continue;
            }
            new_data_[j] = data_[i];
        }

        num_items--;
        data_ = std::move( new_data_ );
    }

    T &operator[]( size_t idx ) {
        try {
            if ( idx >= num_items ) {
                throw std::runtime_error("The index is larger than size");
            }

            return data_[idx];

        } catch ( const std::exception &e ) {
            std::cerr << e.what() << std::endl;
        }
    }

    size_t size() const { return num_items; }

    bool empty() const { return num_items == 0; }

    void clear() { num_items = 0; }

    using iterator       = T *;
    using const_iterator = const T *;

    iterator begin() { return data_.get(); }
    iterator end() { return data_.get() + num_items; }

    const_iterator begin() const { return data_.get(); }

    const_iterator end() const { return data_.get() + num_items; }

private:
    std::unique_ptr<T[]> data_;
    size_t num_items;
};
