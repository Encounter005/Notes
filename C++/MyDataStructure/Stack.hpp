#include "Stack.h"

template<typename T>
std::allocator<T> Stack<T>::alloc;

template<typename T>
void Stack<T>::reallocate() {
    T* newdata = nullptr;

    if(elements == nullptr || cap == nullptr) {
        newdata = alloc.allocate(1);
        elements = newdata;
        first_of_free = newdata;
        cap = newdata + 1;
    } else {
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
std::pair<T* , T*> Stack<T>::alloc_n_copy(const T* be , const T* ed) {
    auto newdata = alloc.allocate(ed - be);
    auto first_free = std::uninitialized_copy(be , ed , newdata);
    return std::make_pair(newdata , first_free);
}

template<typename T>
Stack<T>::Stack(const Stack& other) {
    auto copy = alloc_n_copy(other.begin() , other.end());
    elements = copy.first;
    first_of_free = copy.second;
    cap = copy.second;
}

template<typename T>
Stack<T>::Stack(Stack&& other) {
    auto copy = alloc_n_copy(other.begin() , other.end());
    elements = copy.first;
    first_of_free = copy.second;
    cap = copy.second;
}

template<typename T>
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
Stack<T>::~Stack() {
    free();
}

template<typename T>
void Stack<T>::push(T item) {
    check_n_alloc();
    alloc.construct(first_of_free++ , item);
}

template<typename T>
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

