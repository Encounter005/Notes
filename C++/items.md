# Effective Modern C++

<!--toc:start-->
- [Effective Modern C++](#effective-modern-c)
  - [Item1 模板类型推断](#item1-模板类型推断)
  - [Item2 Understand auto type deduction](#item2-understand-auto-type-deduction)
<!--toc:end-->


## Item1 模板类型推断

Compiler Diagnostics

```c++
template<typename T>
class TypeDisplayer; // NOTE: just defination no declartion

TypeDisplayer<decltype(expression)> test;
```

> Case1 ParamType is a pointer/reference

```c++
namespace {
template<typename ParamType>
void func(ParamType& t) {

}
};
```

1. if has reference , ignore the reference part
2. regular match

```c++
    int x = 10;
    const int cx = x;
    const int& rx = x;

    func(x); // NOTE: T-> int  ParamType int&
    func(cx); // NOTE: T-> const int   ParamType const int&
    func(rx); // NOTE: T-> const int  ParamType const int&

```

> Case2 ParamType is a universal reference

```c++

namespace {
template<typename ParamType>
void func(ParamType&& t) {

}
};
```

1. if l-value -> T&
2. if r-value -> normal rules applies

```c++
    int x = 10;
    const int cx = x;
    const int& rx = x;

    // func(x); // NOTE: T-> int  ParamType int& -> Reference Collapse(引用折叠)
    // func(cx); // NOTE: T-> const int   ParamType const int&
    // func(rx); // NOTE: T-> const int  ParamType const int&
    func(27); // NOTE: T-> int

```

> Case3 ParamType is not a reference / pointer

```c++
#include <iostream>

template<typename T>
class TypeDisplayer;
template<typename T>
void func(T param) {
    TypeDisplayer<decltype(param)> test;
    param = 100;
}


int main() {
    int x = 10;
    const int cx = x;
    const int& rx = x;

    // func(x); // NOTE: T-> int  ParamType int& -> Reference Collapse(引用折叠)
    // func(cx); // NOTE: T-> const int   ParamType const int&
    func(rx); // NOTE: T-> const int  ParamType const int&
    // func(27); // NOTE: T-> int
    // std::cout << rx << std::endl;

    return 0;
}

```

1. ignore reference and const

> Case4 Array Decay

```c++
#include <iostream>

template<typename T>
class TypeDisplayer;
template<typename T>
void func(T& param) {
    // TypeDisplayer<decltype(param)> test;
    // NOTE: if has no reference, is a pointer
    // else is a array
    std::cout << sizeof param << std::endl;
}


int main() {
    const char hello[13] = "nihao"; // NOTE: const char* Array Decay(数组退化成指针)
    func(hello);
    return 0;
}
```

## Item2 Understand auto type deduction

auto 的推断方式基本与`Item1`相同

但是在推断数组的时候不一样

```c++
#include <iostream>

template<typename T>
class TypeDisplayer;

template<typename T>
void func1(T t) {
    TypeDisplayer<decltype(t)> test;
}

int main() {

    auto x = {1 , 2 , 3 , 4}; // NOTE: std::initializer_list<int>
    func1(x);


    return 0;
}

```

```c++
#include <iostream>

template<typename T>
class TypeDisplayer;

template<typename T>
// BUG: template deduction
auto func(T t) {
    return {1 , 2 , 3};
}

int main() {

    return 0;
}

```

1. 在推断数组类型的时候会推断成`std::initializer_list`
2. 在推断函数返回的是一个模板类型，过不了编译
3. 剩下基本和模板推断差不多


## Item3 decltype

> 基本用法 decltype(expression)
```c++
#include <iostream>

template<typename T> 
class TypeDisplayer;

int main() {

    int x = 10;
    const int& c = x;
    const int& s = 100;

    TypeDisplayer<decltype(c)> test;
    return 0;
}


```
> decltype 确认返回值的类型能够

```c++
#include <iostream>
#include <vector>
#include <cassert>

template <typename T> class TypeDisplayer;

template <typename Container, typename Index>
decltype(auto) func(Container&& c, const Index& i ) {
    return std::forward<Container>(c)[i];
    // NOTE: 不使用decltype之前，函数返回值是int，使用之后，函数返回值是int&
}

int main() {
    std::vector<int> a{1 , 4 , 48 , 489 , 382}; 
    int& res = func(std::vector<int>{1 , 3, 48 , 890} , 1);
     
    return 0;
}

```
> decltype通常用于表面一个函数模板的返回值的类型

```c++

decltype(auto) f1() {
    /*
     expression
    */
    retunr x // NOTE: decltype(x) is int , so f1 returns int
}

decltype(auto) f2() {
    /*
     expression
    */
    retunr (x) // NOTE: decltype(x) is int& , so f2 returns int
}
```


## Item23 move和完美转发


