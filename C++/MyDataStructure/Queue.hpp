#pragma once
#include <iostream>
#include <memory>
template <typename T> class Queue {
protected:
    // 内存的头指针
    T *st;
    // 队列的头指针
    T *elements;
    // 队列的尾指针
    T *first_of_free;
    // 内存的尾指针
    T *cap;
    // @brief: 删除队列及内存
    void free();
    size_t check_size() { return first_of_free - st; }
    // @brief: 检查内存空间是否溢出
    void check_n_alloc() {
        if ( size() == capacity() || capacity() == check_size() ) {
            reallocate();
        }
    }
    // @brief: 内存分配函数
    void reallocate();
    // @brief: 内存复制函数
    std::pair<T *, T *> alloc_n_copy( const T *be, const T *ed );
    // 内存分配器
    static std::allocator<T> alloc;

public:
    // 无参构造函数
    Queue()
        : elements( nullptr ), st( nullptr ), first_of_free( nullptr ),
          cap( nullptr ) {}
    // 复制构造函数
    Queue( const Queue & );
    // 移动构造函数
    Queue( Queue && ) noexcept;
    // 复制操作符
    Queue &operator=( const Queue & );
    // 移动操作符
    Queue &operator=( Queue && ) noexcept;
    // 析构函数
    ~Queue();
    // @brief: 插入元素到队尾
    // @param： 要插入的元素
    template <typename U> void push( U && );
    // @brief: 弹出队头
    void pop();
    // @return: 返回队列的大小
    size_t size() const { return first_of_free - elements; }

    // @brief: 检测内存空间大小
    // @return: 内存空间大小
    size_t capacity() const { return cap - st; }

    // @return: 返回头迭代器
    T *begin() const noexcept { return elements; }

    // @return: 返回尾迭代器
    T *end() const noexcept { return first_of_free; }

    // @return: 返回对头元素
    T front() { return *elements; }

    // @return: 检测队列是否为空
    bool empty() {
        return st == nullptr || elements == nullptr || first_of_free == nullptr;
    }
};

template <typename T> std::allocator<T> Queue<T>::alloc;

template <typename T> void Queue<T>::reallocate() {
    T *newdata = nullptr;

    if ( elements == nullptr || cap == nullptr || st == nullptr ) {
        newdata = alloc.allocate( 1 );
        st = elements = newdata;
        first_of_free = newdata;
        cap           = newdata + 1;
    } else {
        newdata   = alloc.allocate( check_size() * 2 );
        auto dest = newdata;
        auto src  = elements;
        for ( size_t i = 0; i < size(); i++ ) {
            alloc.construct( dest++, std::move( *src++ ) );
        }
        free();
        st = elements = newdata;
        first_of_free = dest;
        cap           = elements + size() * 2;
    }
}

template <typename T> void Queue<T>::free() {
    if ( elements != nullptr && st != nullptr ) {
        auto dest = elements;
        for ( size_t i = 0; i < size(); i++ ) {
            alloc.destroy( dest + i );
        }
        alloc.deallocate( st, cap - st );
        st = elements = cap = first_of_free = nullptr;
    }
}

template <typename T>
std::pair<T *, T *> Queue<T>::alloc_n_copy( const T *be, const T *ed ) {
    auto newdata    = alloc.allocate( ed - be );
    auto first_free = std::uninitialized_copy( be, ed, newdata );
    return std::make_pair( newdata, first_free );
}

template <typename T> Queue<T>::Queue( const Queue &other ) {
    auto copy = alloc_n_copy( other.begin(), other.end() );
    st = elements = copy.first;
    first_of_free = copy.second;
    cap           = copy.second;
}

template <typename T> Queue<T>::Queue( Queue &&other ) noexcept {
    st = other.st;
    elements = other.elements;
    cap = other.cap;
    first_of_free = other.first_of_free;
    other.free();
}

template <typename T> Queue<T> &Queue<T>::operator=( const Queue &other ) {
    if ( this == &other ) {
        return *this;
    }

    auto copy = alloc_n_copy( other.begin(), other.end() );
    st = elements = copy.first;
    first_of_free = copy.second;
    cap           = copy.second;
}

template <typename T> Queue<T> &Queue<T>::operator=( Queue &&other ) noexcept {
    if ( this == &other ) {
        return *this;
    }
    st = other.st;
    elements = other.elements;
    cap = other.cap;
    first_of_free = other.first_of_free;
    other.free();

}

template <typename T> Queue<T>::~Queue() { free(); }

template <typename T> template <typename U> void Queue<T>::push( U &&item ) {
    check_n_alloc();
    alloc.construct( first_of_free++, item );
}

template <typename T> void Queue<T>::pop() {
    if ( first_of_free == nullptr ) {
        return;
    }

    if ( size() == 1 ) {
        alloc.destroy( elements );
        st = elements = nullptr;
        first_of_free = nullptr;
        return;
    }

    auto dest = elements++;
    alloc.destroy( dest );
}
