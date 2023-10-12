#include "Array.h"

template <typename T> Array<T>::Array( size_t size_ ) : size( size_ ) {
    if ( size ) {
        data = std::unique_ptr<T[]>( new T[size]() );
    } else {
        data = nullptr;
    }
}

template <typename T> Array<T>::~Array() {
    if ( data != nullptr ) {
        data.release();
    }
    size = 0;
}

template <typename T> Array<T>::Array( const Array &other ) {
    if ( data != nullptr ) {
        data.release();
    }
    data( other.data );
    other.data.release();
}

template <typename T> Array<T>::Array( Array &&other ) {

    if ( data != nullptr ) {
        data.release();
    }
    data( other.data );
    other.data.release();
}

/*
 *  Insert 插入函数
 *
 * @param pos 插入位置 value 数值
 * */

template <typename T> void Array<T>::Insert( size_t pos, T value ) {
    if ( pos > size ) {
        assert( pos > size );
    }
    size++;
    std::unique_ptr<T[]> other( new T[size]() );
    for ( int i = 0, j = 0; i < size; i++ ) {
        if ( i == pos - 1 ) {
            other[i] = value;
        } else {
            other[i] = data[j++];
        }
    }
    std::swap( data, other );
    other.release();
    other = nullptr;
}

/*
 * Delete 删除函数
 *
 * @param pos 删除位置
 **/

template <typename T> void Array<T>::Delete( size_t pos ) {
    if ( pos > size ) {
        assert( pos > size );
    }
    std::unique_ptr<T[]> other( new T[size - 1]() );
    for ( int i = 0, j = 0; i < size; i++ ) {
        if ( i != pos - 1) {
            other[j++] = data[i];
        }
    }
    std::swap(other , data);
    other.release();
    other = nullptr;
    size--;
}

/*
 * Find 查找函数
 *
 * @param pos 查找位置
 *
 * @return 这个位置上的元素
 *
 * */

template <typename T> T Array<T>::find( size_t pos ) {
    if ( pos < 0 || pos > size ) {
        return -1;
    }
    return data[pos - 1];
}

/*
 * begin
 *
 * @return 返回数组的头
 *
 * */

template <typename T> T &Array<T>::begin() const { return data[0]; }

/*
 * end
 *
 * @return 返回数组的末尾
 *
 * */

template <typename T> T &Array<T>::end() const { return data[size - 1]; }

/*
 * cnt
 *
 * @return 数组的大小
 * */

template <typename T> size_t Array<T>::cnt() const { return size; }

template <typename T> Array<T>::Array( std::initializer_list<T> &&param ) {
    if ( data != nullptr ) {
        data.release();
        size = 0;
        data = nullptr;
    }

    if ( param.size() ) {
        unsigned int cnt = 0;
        data             = std::unique_ptr<T[]>( new T[param.size()] );
        for(const auto& elem : param) {
            data[cnt++] = elem;
        }
        size = cnt;
    } else {
        data = nullptr;
    }
}

template <typename T> Array<T>::Array( const std::initializer_list<T> &param ) {
    if ( data != nullptr ) {
        data.release();
        size = 0;
        data = nullptr;
    }

    if ( param.size() ) {
        unsigned int cnt = 0;
        data             = std::unique_ptr<T[]>( new T[param.size()] );
        for(const auto& elem : param) {
            data[cnt++] = elem;
        }
        size = cnt;
    } else {
        data = nullptr;
    }
}

template <typename T> T &Array<T>::operator[]( size_t pos ) const {
    if(pos >= size) {
        assert(pos >= size);
    } else {
        return data[pos];
    }
}

template<typename T>
void Array<T>::clear() {
    data.release();
    data = nullptr;
    size = 0;
}

template<typename T>
bool Array<T>::empty() {
    return size == 0;
}
