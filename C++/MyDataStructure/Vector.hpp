#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <memory>

template<typename T> 
class TD;



template <typename T> class Vector {
private:
    T *first_of_free;
    T *elements;
    T *cap;

    void chk_no_space();
    void free();
    void reallocate();
    std::pair<T *, T *> alloc_n_copy( const T *be, const T *ed );
    static std::allocator<T> alloc;
    size_t capacity() { return cap - elements; }

public:
    Vector() {
        first_of_free = nullptr;
        elements      = nullptr;
        cap           = nullptr;
    }

    Vector( size_t n );
    Vector( std::initializer_list<T> &iilst );
    Vector( std::initializer_list<T> &&iilst );
    Vector( const Vector & );
    Vector( Vector && ) noexcept;
    ~Vector() { free(); }
    template <typename U> void push_back( U &&n );
    template <typename... Args> void emplace_back( Args &&... );
    void pop_back();
    void clear() { free(); }
    size_t size() { return first_of_free - elements; }
    Vector &operator=( const Vector & );
    T front() const { return *elements; }
    T back() const { return *( first_of_free - 1 ); }
    T *begin() const { return elements; }
    T *end() const { return first_of_free; }
    T operator[]( size_t index );
};

template <typename T> typename std::allocator<T> Vector<T>::alloc;

template <typename T> void Vector<T>::reallocate() {
    T *newdata = nullptr;
    if ( elements == nullptr || cap == nullptr ) {
        newdata  = alloc.allocate( 1 );
        elements = first_of_free = newdata;
        cap                      = newdata + 1;
    } else {
        newdata   = alloc.allocate( capacity() * 2 );
        auto dest = newdata;
        auto src  = elements;
        for ( size_t i = 0; i < size(); i++ ) {
            alloc.construct( dest++, *( src + i ) );
        }
        free();
        elements      = newdata;
        first_of_free = dest;
        cap           = elements + size() * 2;
    }
}

template <typename T> void Vector<T>::chk_no_space() {
    if ( size() == capacity() ) {
        reallocate();
    }
}

template <typename T>
std::pair<T *, T *> Vector<T>::alloc_n_copy( const T *be, const T *ed ) {
    auto newdata = alloc.allocate( ed - be );
    auto dest    = std::uninitialized_copy( be, ed, newdata );
    return { newdata, dest };
}

template <typename T> void Vector<T>::free() {
    if ( elements ) {
        auto dest = elements;
        for ( size_t i = 0; i < size(); i++ ) {
            alloc.destroy( dest + i );
        }
        alloc.deallocate( elements, cap - elements );
        elements = first_of_free = cap = nullptr;
    }
}

template <typename T> template <typename U> void Vector<T>::push_back( U &&n ) {
    chk_no_space();
    alloc.construct( first_of_free++, n );
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace_back( Args &&...args ) {
    chk_no_space();
    alloc.construct( first_of_free++, std::forward<Args>( args )... );
}

template <typename T> void Vector<T>::pop_back() {
    if ( first_of_free == nullptr ) {
        return;
    }

    if ( size() == 1 ) {
        auto dest = elements;
        alloc.destroy( dest );
        elements      = nullptr;
        first_of_free = nullptr;
        return;
    }

    alloc.destroy( --first_of_free );
}

template <typename T> Vector<T>::Vector( size_t n ) {
    auto newdata = alloc.allocate( n );
    elements     = newdata;
    auto dest    = newdata;
    for ( size_t i = 0; i < n; i++ ) {
        alloc.construct( dest++, 0 );
    }
    first_of_free = dest;
    cap           = elements + size();
}

template <typename T> Vector<T>::Vector( const Vector &other ) {
    auto [st, ed] = alloc_n_copy( other.begin(), other.end() );
    elements      = st;
    first_of_free = ed;
    cap           = ed;
}

template <typename T>
Vector<T>::Vector( Vector &&other ) noexcept
    : elements( other.elements ), cap( other.cap ),
      first_of_free( other.first_of_free ) {
    other.cap = other.first_of_free = other.elements = nullptr;
}

template <typename T> Vector<T> &Vector<T>::operator=( const Vector &other ) {
    if ( this == &other ) {
        return *this;
    }
    if ( this->capacity() ) {
        this->clear();
    }

    auto [be, ed] = alloc_n_copy( other.begin(), other.end() );
    elements      = be;
    first_of_free = ed;
    cap           = ed;
    return *this;
}
template <typename T> Vector<T>::Vector( std::initializer_list<T> &ilist ) {
    auto newdata = alloc.allocate( ilist.end() - ilist.begin() );
    auto dest = std::uninitialized_copy(ilist.begin() , ilist.end() , newdata);
    elements = newdata;
    cap = first_of_free = dest;
}

template <typename T> Vector<T>::Vector( std::initializer_list<T> &&ilist ) {
    auto newdata = alloc.allocate( ilist.end() - ilist.begin() );
    auto dest = std::uninitialized_copy(ilist.begin() , ilist.end() , newdata);
    elements = newdata;
    cap = first_of_free = dest;
}

template <typename T> T Vector<T>::operator[]( size_t index ) {
    if ( index < size() && index >= 0) {
        return *( elements + index );
    } else {
        throw "error index\n";
    }
}
