#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T> class Stack {
private:
    // 第一个元素的指针
    T *elements;
    // 第一个空位的指针
    T *first_of_free;
    // 内存空间的尾节点
    T *cap;

    void free();
    /* @brief 检查当前内存空间是否已用完，如果用完将重新分配
     *
     */
    void check_n_alloc() {
        if ( size() == capacity() ) {
            reallocate();
        }
    }
    void reallocate();

    std::pair<T *, T *> alloc_n_copy( const T *be, const T *ed );
    static std::allocator<T> alloc;

public:
    // @brief 无参构造函数
    Stack() : elements( nullptr ), first_of_free( nullptr ), cap( nullptr ) {}
    Stack( const Stack & );
    Stack( Stack && ) noexcept;
    Stack &operator=( const Stack & );
    Stack &operator=( Stack && ) noexcept;
    ~Stack();
    void push( T );
    void pop();
    //@brief 检测容器中元素的数量
    //@return 返回元素的数量
    size_t size() const { return first_of_free - elements; }
    //@brief 检测容器内存空间的大小
    //@return 返回容器所占内存空间的大小
    size_t capacity() const { return cap - elements; }

    //@return 返回第一个元素的地址
    T *begin() const noexcept { return elements; }
    //@return 返回第一个容器中第一个空闲位置
    T *end() const noexcept { return first_of_free; }
    //@return 返回栈顶
    T &top() { return *( first_of_free - 1 ); }
    //@brief 检测栈是否为空
    //@return 返回bool值
    bool empty() { return elements == nullptr || cap == nullptr; }
    //@brief 清空容器并释放内存
    void clear() { free(); }
    // 重载<<操作符，用于输出
    friend std::ostream &operator<<( std::ostream &os, Stack &other ) {
        auto p = other;
        while ( p.size() ) {
            os << p.top() << " ";
            p.pop();
        }
        os << std::endl;
        return os;
    }
};

template <typename T>
// 初始化内存分配器
std::allocator<T> Stack<T>::alloc;

template <typename T>
// @brief 重新分配内存
void Stack<T>::reallocate() {
    T *newdata = nullptr;
    // 如果发现容器是第一次使用，就直接初始化即可
    if ( elements == nullptr || cap == nullptr ) {
        newdata       = alloc.allocate( 1 );
        elements      = newdata;
        first_of_free = newdata;
        cap           = newdata + 1;
    } else {
        // 如果容器是内存已满要重新分配的话，那就开辟新的比原来大两倍的内存空间，再将数据拷贝过去
        newdata   = alloc.allocate( size() * 2 );
        auto dest = newdata;
        auto src  = elements;
        for ( size_t i = 0; i < size(); i++ ) {
            alloc.construct( dest++, std::move( *src++ ) );
        }
        free();
        elements      = newdata;
        first_of_free = dest;
        cap           = elements + size() * 2;
    }
}

template <typename T>
//@brief 内存释放
void Stack<T>::free() {
    if ( elements != nullptr ) {
        auto dest = elements;
        for ( size_t i = 0; i < size(); i++ ) {
            alloc.destroy( dest + i );
        }
        alloc.deallocate( elements, cap - elements );
        elements = cap = first_of_free = nullptr;
    }
}

template <typename T>
//@brief 内存拷贝
std::pair<T *, T *> Stack<T>::alloc_n_copy( const T *be, const T *ed ) {
    auto newdata    = alloc.allocate( ed - be );
    auto first_free = std::uninitialized_copy( be, ed, newdata );
    return std::make_pair( newdata, first_free );
}

template <typename T>
//@brief 复制构造函数
Stack<T>::Stack( const Stack &other ) {
    auto copy     = alloc_n_copy( other.begin(), other.end() );
    elements      = copy.first;
    first_of_free = copy.second;
    cap           = copy.second;
}

template <typename T>
//@brief 移动构造函数
Stack<T>::Stack( Stack &&other ) noexcept {
    elements = other.elements;
    first_of_free = other.first_of_free;
    cap = other.cap;
    other.free();
}

template <typename T>
//@brief 重载拷贝复制运算符
Stack<T> &Stack<T>::operator=( const Stack &other ) {
    if ( this == &other ) {
        return *this;
    }

    auto copy     = alloc_n_copy( other.begin(), other.end() );
    elements      = copy.first;
    first_of_free = copy.second;
    cap           = copy.second;
}

template <typename T>
//@brief 重载移动运算符
Stack<T> &Stack<T>::operator=( Stack &&other ) noexcept {
    if ( this == &other ) {
        return *this;
    }
    elements = other.elements;
    first_of_free = other.first_of_free;
    cap = other.cap;
    other.free();
}

template <typename T>
// @brief 析构函数
Stack<T>::~Stack() {
    free();
}

template <typename T>
// @brief 插入函数
// @param item 要添加的元素
void Stack<T>::push( T item ) {
    check_n_alloc();
    alloc.construct( first_of_free++, item );
}

template <typename T>
// @brief 删除函数，弹出栈顶
void Stack<T>::pop() {
    if ( first_of_free == nullptr ) {
        return;
    }

    if ( size() == 1 ) {
        alloc.destroy( elements );
        elements      = nullptr;
        first_of_free = nullptr;
        return;
    }

    alloc.destroy( first_of_free-- );
}
