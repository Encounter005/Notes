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
    friend std::ostream& operator<<(std::ostream& os , Stack& other) {
        auto p = other;
        while(p.size()) {
            os << p.top() << " ";
            p.pop();
        }
        os << std::endl;
        return os;
    }
};
