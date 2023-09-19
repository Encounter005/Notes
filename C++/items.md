# Effective Modern C++

<!--toc:start-->

- [Effective Modern C++](#effective-modern-c)
  - [Item1 模板类型推断](#item1-模板类型推断)
  - [Item2 Understand auto type deduction](#item2-understand-auto-type-deduction)
  - [Item3 decltype](#item3-decltype)
  - [Item23 move和完美转发](#item23-move和完美转发)
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

注意：不要将`auto`用在返回类型为`bool`的函数上

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


## Item5 Prefer auto to explicit type declartion

```c++
#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include <unordered_map>

class A {
public:
    A(){}
    A(const A&) {
        std::cout << "In Copy Constructor" << std::endl;
    }

    bool operator==(const A& a) const {
        return false;
    }
};
namespace std {
template<>
struct hash<A> {
    std::size_t operator()(const A& a) const {
        return 1;
    }
};
};
namespace {
template<typename T> 
class TypeDisplayer;


void Func() {
    A a1 , a2;
    std::unordered_map<A , int> m = {{a1 , 123} , {a2 , 4667}};
    std::cout << "begin interation" << std::endl;

    for(const std::pair<const A , int> &p : m) {
        std::cout << p.second << std::endl;
    } // NOTE: 必须加const，使first变成一个常量，否则会出现额外的拷贝

    for(const auto& i : m) {
        std::cout << i.second << std::endl;
    }
}
};



int main() {
    std::vector<int> a;
    std::vector<int>::iterator it = a.begin();
    auto it2 = a.begin(); 
    
    std::function<void(const std::string&)> func = [](const std::string& t)->void{
        std::cout << t << std::endl;
    };

    auto func2 = [](const std::string& t)->void{
        std::cout << t << std::endl;
    };

    Func();

    return 0;
}

```


1) 可以有效减少我们打字的量
2) 可以确保变量初始化(不初始化过不了编译)
3) 可以避免额外的拷贝

## Item6


## Item7

## Item14 noexcept的好处

> 1. 介绍

该关键字告诉编译器，函数中不会发生异常，这有利于编译器对程序做更多的优化  
如果在运行是，noexcept函数向外抛出了异常（如果函数内部捕捉了异常并完成处理，这种情况不算抛出异常），程序会直接终止，调用`std::terminate()`函数，该函数内部会调用`std::abort()`终止程序

> 2. 使用

C++中异常处理是在运行时而不是在编译时检测的。为了实现实时运行检测，编译器创建额外的代码，然而这会妨碍程序优化。  
在实践中，一般两种异常抛出方式是常用的：

- 一个操作或者函数可能会抛出异常
- 一个操作或者函数不可能抛出任何异常

```c++
    void swap(Type& x, Type& y) throw()   //C++11之前
    {
        x.swap(y);
    }
    void swap(Type& x, Type& y) noexcept  //C++11
    {
        x.swap(y);
    }
```

> 3. 有条件的noexcept

在第2节中单独使用noexcept，表示其所限定的swap函数绝对不发生异常。然而，使用方式可以更加灵活，表明在一定条件下不发生异常。

```c++
    void swap(Type& x, Type& y) noexcept(noexcept(x.swap(y)))    //C++11
    {
        x.swap(y);
    }
```

它表示，如果操作x.swap(y)不发生异常，那么函数swap(Type& x, Type& y)一定不发生异常。

> 4. 什么时候该使用noexcept

- 移动构造函数
- 移动分配函数
- 析构函数


## Item15 constexpr的灵活性


## Item23 move和完美转发

> std::move()是将当前值转化为右值，如果是左值，将变成右值，如果是右值，依旧是右值

> std::forward<T>()是保持当前值的属性，如果是左值依旧是左值，如果是右值依旧是右值

```c++
#include <iostream>

namespace {
class A {
public:
    A() {
        std::cout << "In default Constructor" << std::endl;
    }
    A(const A& rhs) {
        std::cout << "In copy Constructor" << std::endl;
    }
    A(A&& rhs) {
        std::cout << "In move Constructor" << std::endl;
    }
    ~A() {}
};

class Annotation {

public:
    explicit Annotation(const A& text) : value_(std::move(text)) {}

private:
    A value_;

};
};

int main() {
    A a;
    Annotation t(a);

    return 0;
}

```

1. 在上面的代码中调用了一次A类的构造函数和复制构造函数，并没有调用移动构造函数
2. 如果我们想要把右值绑定到一个左值引用上，我们必须在前面加上`const`确保我们不会修改这个右值。所以为了确保传进去的变量在构造的时候调用移动构造函数，必须把`const`去掉

```c++
#include <iostream>

namespace {
class A {
public:
    A() {
        std::cout << "In default Constructor" << std::endl;
    }
    A(const A& rhs) {
        std::cout << "In copy Constructor" << std::endl;
    }
    A(A&& rhs) {
        std::cout << "In move Constructor" << std::endl;
    }
    ~A() {}
};

class Annotation {

public:
    explicit Annotation(A& text) : value_(std::move(text)) {}
    // NOTE:只需要把const去掉就可以了，因为const左值引用让text依旧是左值，会调用复制构造函数

private:
    A value_;

};
};

int main() {
    A a;
    Annotation t(a);

    return 0;
}

```
