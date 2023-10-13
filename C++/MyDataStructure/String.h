#ifndef __STR_VEC_H__
#define __STR_VEC_H__
#include <iostream>
#include <memory>
#include <assert.h>
#include <string>

class StrVec {
public:
    //@description: no param constructor
    StrVec() : elements( nullptr ), first_free( nullptr ), cap( nullptr ){};
    //@description: copy constructor
    StrVec( const StrVec & );
    //@desription: move constructor
    StrVec(StrVec &&);
    //@description: copy operator
    StrVec &operator=( const StrVec & );
    //@description: move operator
    StrVec &operator=(StrVec&&) noexcept;
    std::string &operator[](size_t pos) const; 
    //@description: destructor
    ~StrVec();
    //@description: copy element
    //@param __value: 要添加的元素
    void push_back( const std::string & );
    //@description: 弹出元素
    //@param: __value 弹出的元素
    void pop_back( std::string & );
    //@return: 返回数组长度
    size_t size() const { return first_free - elements; }
    //@return: 返回容量
    size_t capacity() const { return cap - elements; }
    //@return: 返回首元素地址
    std::string *begin() const { return elements; }
    //@return: 返回第一个空闲元素，也是返回有效元素的下一个位置
    std::string *end() const { return first_free; }

private:
    // 数组首元素指针
    std::string *elements;
    // 指向数组的第一个空闲指针
    std::string *first_free;
    // 指向数组的最后一位的空闲指针
    std::string *cap;
    // 构造string类型allocator静态成员

    //@description: 判断容量不足开辟新的空间
    void chk_n_alloc() {
        if ( size() == capacity() ) {
            reallocate();
        }
    }
    //@description: 释放空间
    void free();
    //@description: 重新开辟空间
    void reallocate();
    // @description: copy指定范围内的元素到新的内存空间中
    // @param __st 头指针
    // @param __ed 尾指针
    // @return: 返回新的元素的地址和第一个空闲元素的地址
    std::pair<std::string *, std::string *> alloc_n_copy(
        const std::string *, const std::string * );
    static std::allocator<std::string> alloc;
};

#endif 
