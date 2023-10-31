// Filename: Queue.h

#pragma once
#include <iostream>
#include <memory>
template<typename T>
class Queue {
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
    size_t check_size() {
        return first_of_free - st;
    }
    // @brief: 检查内存空间是否溢出
    void check_n_alloc() {
        if(size() == capacity() || capacity() == check_size()) {
            reallocate();
        }
    }
    // @brief: 内存分配函数
    void reallocate();
    // @brief: 内存复制函数
    std::pair<T* , T*> alloc_n_copy(const T* be, const T* ed);
    // 内存分配器
    static std::allocator<T> alloc;

public:
    // 无参构造函数
    Queue() : elements(nullptr) , st(nullptr) ,  first_of_free(nullptr) , cap(nullptr) {}
    // 复制构造函数
    Queue(const Queue& );
    // 移动构造函数
    Queue(Queue&& );
    // 复制操作符
    Queue &operator=(const Queue& );
    // 移动操作符
    Queue &operator=(Queue&& ) noexcept;
    // 析构函数
    ~Queue() ;
    // @brief: 插入元素到队尾
    // @param： 要插入的元素
    void push(T);
    // @brief: 弹出队头
    void pop();
    // @return: 返回队列的大小
    size_t size() const {
        return first_of_free - elements;
    }

    // @brief: 检测内存空间大小
    // @return: 内存空间大小
    size_t capacity() const {
        return cap - st;
    }

    // @return: 返回头迭代器
    T* begin() const noexcept {
        return elements;
    }

    // @return: 返回尾迭代器
    T* end() const noexcept {
        return first_of_free;
    }

    // @return: 返回对头元素
    T front() {
        return *elements;
    }

    // @return: 检测队列是否为空
    bool empty() {
        return st == nullptr || elements == nullptr || first_of_free == nullptr;
    }

    
};




