#include <cstdio>
#include <iostream>
#include <memory>
#include <alloca.h>

template<typename T>
class Stack {
private:
    T *elements;
    T *first_of_free;
    T *cap;
    void free();
    void check_n_alloc() {
        if(size() == capacity()) {
            reallocate();
        }
    }
    void reallocate();

    std::pair<T* , T*> alloc_n_copy(const T* be, const T* ed);
    static std::allocator<T> alloc;

public:
    
    Stack() : elements(nullptr) , first_of_free(nullptr) , cap(nullptr) {
    }
    Stack(const Stack& );
    Stack(Stack&& );
    Stack &operator=(const Stack& );
    Stack &operator=(Stack&& ) noexcept;
    ~Stack() ;
    void push(T);
    void pop();
    size_t size() const {
        return first_of_free - elements;
    }
    size_t capacity() const {
        return cap - elements;
    }

    T* begin() const noexcept {
        return elements;
    }
    
    T* end() const noexcept {
        return first_of_free;
    }

    T& top() {
        return *(first_of_free - 1);
    }

    bool empty() {
        return elements == nullptr || cap == nullptr;
    }

    
};




