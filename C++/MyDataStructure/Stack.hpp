#pragma once
#include "Stack.h"

template<typename T>
// 初始化内存分配器
std::allocator<T> Stack<T>::alloc;

template<typename T>
// @brief 重新分配内存
void Stack<T>::reallocate() {
    T* newdata = nullptr;
    // 如果发现容器是第一次使用，就直接初始化即可
    if(elements == nullptr || cap == nullptr) {
        newdata = alloc.allocate(1);
        elements = newdata;
        first_of_free = newdata;
        cap = newdata + 1;
    } else {
        // 如果容器是内存已满要重新分配的话，那就开辟新的比原来大两倍的内存空间，再将数据拷贝过去
        newdata = alloc.allocate(size() * 2);
        auto dest = newdata;
        auto src = elements;
        for(size_t i = 0; i < size(); i++ ) {
            alloc.construct(dest++, std::move(*src++));
        }
        free();
        elements = newdata;
        first_of_free = dest;
        cap = elements + size() * 2;
    }
}

template<typename T>
//@brief 内存释放
void Stack<T>::free() {
    if(elements != nullptr) {
        auto dest = elements;
        for(size_t i = 0; i < size(); i++) {
            alloc.destroy(dest + i);
        }
        alloc.deallocate(elements , cap - elements);
        elements = cap = first_of_free = nullptr;
    }
}

template<typename T>
//@brief 内存拷贝
std::pair<T* , T*> Stack<T>::alloc_n_copy(const T* be , const T* ed) {
    auto newdata = alloc.allocate(ed - be);
    auto first_free = std::uninitialized_copy(be , ed , newdata);
    return std::make_pair(newdata , first_free);
}

template<typename T>
//@brief 复制构造函数
Stack<T>::Stack(const Stack& other) {
    auto copy = alloc_n_copy(other.begin() , other.end());
    elements = copy.first;
    first_of_free = copy.second;
    cap = copy.second;
}

template<typename T>
//@brief 移动构造函数
Stack<T>::Stack(Stack&& other) noexcept {
    auto copy = alloc_n_copy(other.begin() , other.end());
    elements = copy.first;
    first_of_free = copy.second;
    cap = copy.second;
}

template<typename T>
//@brief 重载拷贝复制运算符
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if(this == &other) {
        return *this;
    }

    auto copy = alloc_n_copy(other.begin() , other.end());
    elements = copy.first;
    first_of_free = copy.second;
    cap = copy.second;
}

template<typename T>
//@brief 重载移动运算符
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept {
    if(this == &other) {
        return *this;
    }

    auto copy = alloc_n_copy(other.begin() , other.end());
    elements = copy.first;
    first_of_free = copy.second;
    cap = copy.second;
}

template<typename T>
// @brief 析构函数
Stack<T>::~Stack() {
    free();
}

template<typename T>
// @brief 插入函数
// @param item 要添加的元素
void Stack<T>::push(T item) {
    check_n_alloc();
    alloc.construct(first_of_free++ , item);
}

template<typename T>
// @brief 删除函数，弹出栈顶
void Stack<T>::pop() {
    if(first_of_free == nullptr) {
        return;
    }

    if(size() == 1) {
        alloc.destroy(elements);
        elements = nullptr;
        first_of_free = nullptr;
        return;
    }

    alloc.destroy(first_of_free--);
}

