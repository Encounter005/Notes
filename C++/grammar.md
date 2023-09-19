# Grammar of strange

<!--toc:start-->

- [Grammar of strange](#grammar-of-strange)
  - [类](#类)
    - [1. 类的介绍、构造函数、析构函数](#1-类的介绍构造函数析构函数)
    - [2. 类的权限修饰](#2-类的权限修饰)
    - [3. "This" , 常成员函数与常对象](#3-this-常成员函数与常对象)
      - [this 关键字](#this-关键字)
      - [常成员函数、常对象](#常成员函数常对象)
    - [inline, mutable, default, delete](#inline-mutable-default-delete)
      - [1. inline 关键字](#1-inline-关键字)
      - [2. mutable 关键字](#2-mutable-关键字)
      - [3. default 关键字](#3-default-关键字)
      - [4. delete 关键字](#4-delete-关键字)
    - [友元类和友元函数](#友元类和友元函数)
      - [1. 友元的介绍，友元就是可以让另一个类或函数访问私有成员的简单写法](#1-友元的介绍友元就是可以让另一个类或函数访问私有成员的简单写法)
      - [2. 注意](#2-注意)
    - [(\*\*)重载运算符](#重载运算符)
      - [1. 重载运算符的作用](#1-重载运算符的作用)
      - [注意](#注意)
      - [例子](#例子)
      - [总结](#总结)
    - [(\*\*\*)类的继承](#类的继承)
      - [介绍](#介绍)
      - [原理](#原理)
      - [注意事项](#注意事项)
      - [总结](#总结)
    - [(\*\*)虚函数及其实现原理， overide 关键字](#虚函数及其实现原理-overide-关键字)
      - [介绍](#介绍)
      - [注意事项](#注意事项)
      - [总结](#总结)
    - [静态成员变量与静态成员函数](#静态成员变量与静态成员函数)
      - [1. 静态成员变量](#1-静态成员变量)
      - [2. 静态成员变量的注意事项](#2-静态成员变量的注意事项)
      - [3. 静态成员变量的特点](#3-静态成员变量的特点)
    - [(\*) 纯虚函数](#纯虚函数)
      - [介绍](#介绍)
      - [总结](#总结)
    - [RTTI](#rtti)
      - [1. 介绍](#1-介绍)
      - [2. 使用场景](#2-使用场景)
      - [3. 使用方式](#3-使用方式)
      - [4. 注意事项](#4-注意事项)
      - [5. 总结](#5-总结)
    - [多继承](#多继承)
      - [1. 多继承的概念](#1-多继承的概念)
      - [2. 多继承的注意点](#2-多继承的注意点)
      - [3. 总结](#3-总结)
    - [虚继承及其实现原理](#虚继承及其实现原理)
      - [概念](#概念)
      - [实现原理介绍](#实现原理介绍)
      - [总结](#总结)
    - [(\*\*)移动构造函数与移动运算符](#移动构造函数与移动运算符)
      - [1. 对象移动的概念](#1-对象移动的概念)
      - [2. 移动语义为什么可以提高运行效率](#2-移动语义为什么可以提高运行效率)
      - [3. 默认移动构造函数和默认移动赋值运算符](#3-默认移动构造函数和默认移动赋值运算符)
  - [函数重载 overlord](#函数重载-overlord)
  - [内联函数](#内联函数)
  - [new 关键字 (\*)](#new-关键字)
    - [1. new 关键字是 C++用来动态分配内存的主要方式](#1-new-关键字是-c用来动态分配内存的主要方式)
    - [2. 内存泄露（常见 bug）](#2-内存泄露常见-bug)
  - [const 关键字](#const-关键字)
  - [(\*\*)auto 关键字](#auto-关键字)
  - [decltye关键字](#decltye关键字)
    - [简单使用](#简单使用)
    - [decltype(auto)的一些区别](#decltypeauto的一些区别)
  - [静态变量，指针和引用(\*)](#静态变量指针和引用)
    - [关于 const 和 pointer](#关于-const-和-pointer)
  - [左值，右值，左值引用，右值引用(\*\*)](#左值右值左值引用右值引用)
    - [1. 左值和右值](#1-左值和右值)
    - [2. 引用的分类](#2-引用的分类)
  - [move 函数，临时对象(\*\*)](#move-函数临时对象)
    - [1. move 函数](#1-move-函数)
    - [2. 临时对象](#2-临时对象)
  - [万能引用和引用折叠](#万能引用和引用折叠)
    - [万能引用](#万能引用)
    - [引用折叠](#引用折叠)
  - [可调用对象(\*\*)](#可调用对象)
    - [1. 函数](#1-函数)
    - [2. 仿函数](#2-仿函数)
    - [3. lambda 表达式](#3-lambda-表达式)
      - [lambda 表达式各个组件介绍](#lambda-表达式各个组件介绍)
  - [智能指针](#智能指针)
    - [1. 智能指针概述](#1-智能指针概述)
    - [2. shared_ptr](#2-sharedptr)
      - [1. 工作原理](#1-工作原理)
      - [2. 常用操作](#2-常用操作)
        - [1. 初始化](#1-初始化)
        - [2. shared_ptr 的引用计数](#2-sharedptr-的引用计数)
      - [3. 把 shared_ptr 当成普通指针使用](#3-把-sharedptr-当成普通指针使用)
      - [4. 常用函数](#4-常用函数)
      - [5. 关于智能指针创建数组的问题](#5-关于智能指针创建数组的问题)
      - [6. 用智能指针作为参数传递时直接值传递就行](#6-用智能指针作为参数传递时直接值传递就行)
      - [7. 总结](#7-总结)
    - [3. weak_ptr](#3-weakptr)
      - [1. 介绍](#1-介绍)
      - [2. shared_ptr 循环引用的问题](#2-sharedptr-循环引用的问题)
      - [3. weak_ptr 的作用原理](#3-weakptr-的作用原理)
      - [4. 总结](#4-总结)
    - [(\*)unique_ptr](#uniqueptr)
      - [1. 介绍](#1-介绍)
      - [2. unique_ptr 的初始化](#2-uniqueptr-的初始化)
      - [3. unique_ptr 的常用操作](#3-uniqueptr-的常用操作)
    - [(\*\*)智能指针的适用范围](#智能指针的适用范围)
      - [1. 能使用智能指针就尽量是用智能指针 ， 但是有些情况下不能使用智能指针](#1-能使用智能指针就尽量是用智能指针-但是有些情况下不能使用智能指针)
      - [2. 我们应该是用哪个智能指针呢？](#2-我们应该是用哪个智能指针呢)
  - [模板与泛型编程](#模板与泛型编程)
    - [模板介绍，类模板与模板实现原理](#模板介绍类模板与模板实现原理)
      - [1. 模板的介绍](#1-模板的介绍)
      - [2. 类模板基础](#2-类模板基础)
      - [3. 模板的实现原理](#3-模板的实现原理)
    - [(\*) "initializer_list" 和 "typename"](#initializer-list-和-typename)
      - [initializer_list](#initializerlist)
      - [typename](#typename)
    - [(\*)函数模板，成员函数模板](#函数模板成员函数模板)
      - [2. 成员函数模板](#2-成员函数模板)
    - [(\*) 默认模板参数](#默认模板参数)
    - [(\*) 模板的重载、全特化和偏特化](#模板的重载-全特化和偏特化)
      - [1. 模板的重载](#1-模板的重载)
      - [2. 模板的特化](#2-模板的特化)
        - [总结](#总结)
  - [STL](#stl)
  - [IO 库](#io-库)
    - [IO 库介绍](#io-库介绍)
      - [IO](#io)
      - [IO 库组成部分](#io-库组成部分)
    - [(\*)IO库的注意事项](#io库的注意事项)
    - [内存与输入输出设备的交互](#内存与输入输出设备的交互)
    - [内存与磁盘的交互](#内存与磁盘的交互)
- [多线程](#多线程)
  - [多线程的概念](#多线程的概念)
    - [多线程的重要性](#多线程的重要性)
    - [并发与并行的介绍](#并发与并行的介绍)
    - [进程的概念](#进程的概念)
    - [线程的概念](#线程的概念)
    - [总结](#总结)
  - [(\*)线程的创建](#线程的创建)
    - [(\*)传递线程参数](#传递线程参数)
      - [传递参数注意事项](#传递参数注意事项)
      - [总结](#总结)
      - [std::ref 的用法](#stdref-的用法)
    - [(\*)线程 id 的概念](#线程-id-的概念)
      - [线程 id 的定义](#线程-id-的定义)
      - [注意](#注意)
  - [(\*)数据共享与保护](#数据共享与保护)
    - [扩展一下关于汇编的知识](#扩展一下关于汇编的知识)
    - [数据保护问题](#数据保护问题)
    - [互斥锁](#互斥锁)
    - [原子操作](#原子操作)
      - [总结](#总结)
    - [(\*)死锁](#死锁)
- [稀碎的小知识点](#稀碎的小知识点)
  - [memset](#memset)
  <!--toc:end-->

## 类

C 语言的结构体

```c
struct TEST
{ // NOTE: C语言的结构体不能有函数
  // why： 因为一个结构体对象是要声明在栈或者堆中，而任何一个函数都要声明在代码区中
  int i;
  int t;
};

```

C++类的本质就是 C 语言的结构体外加几个类外的函数，C++最后都要转化为 C 语言来实现，类外的函数就是通过 this 来指向这个类的

### 1. 类的介绍、构造函数、析构函数

1. 面试的时候经常会听到一个问题，谈一下对面向对象和面向过程的理解

   1. 面向对象和面向过程是一个相对的概念
   2. 面向过程是按照计算机的工作逻辑来编码的方式，最典型的面向过程的语言就是 C 语言了，C 语言直接对应汇编，汇编又对应电路
   3. 面向对象是按照人类的思维来编码的一种方式，C++完全支持面向对象功能，可以按照人类的思维来处理问题
   4. 举个例子，要把大象装冰箱，按照人类的思路自然是分三步，打开冰箱，将大象装进去，关上冰箱。

   要实现这三步，我们就要首先有人，冰箱这两个对象。人有给冰箱发指令的能 力，冰箱有能够接受指令并打开或关闭门的能力。
   但是从计算机的角度讲，计算机只能定义一个叫做人和冰箱的结构体。人有手这个部位，冰箱有门这个部位。然后从天而降一个函数，是这个函数让手打开了冰箱，又是另一个函数让大象进去，再是另一个函数让冰箱门关上。
   那么，如何用面向过程的 c 语言模拟出面向对象的能力呢？类就诞生了，在类中可以定义专属于类的函数，让类有了自己的动作。回到那个例子，人的类有了让冰箱开门的能力，冰箱有了让人打 开的能力，不再需要天降神秘力量了。
   从开发者的角度讲，面向对象显然更利于程序设计。用面色过程的开发方式，程序一旦大了，各种从天而降的函数会非常繁琐，一些用纯 c 写的大型程序，实际上也是模拟了面向对象的方式。

```c++
#include <iostream>

// NOTE: 面向对象一大的特点就是能在类中定义函数

class IceChest {

public:
  // NOTE: 冰箱开门或关门
  void openDoor() {}
  void closeDoor() {}
};

class Person {
public:
  // NOTE: 人能打开或关闭冰箱
  void openIceChest(const IceChest &iceChest) {}
};

int main() { return 0; }

```

2. 构造函数

类相当于定义了一个新类型，该类型生成在堆或栈上的对象时内存排布和 C 语言相同。但是 C++规定，C++有在类对象创建时就在对应内存将数据初始化的能力，这就是构造函数

![Screenshot_20230222_101927_com.baidu.netdisk.jpg](https://img1.imgtp.com/2023/02/22/X5acsPGz.jpg)

```c++
#include <iostream>

// 仿C写法
struct CTest { // NOTE: C语言是无法在定义对象是将里面的数据初始化的
  int i;
  int i2;
};

struct CPPTest {
public:
  CPPTest(int i_, int i2_) : i(i_), i2(i2_) {}

  //复制构造函数
  CPPTest(const CPPTest& t2) :i(t2.i) , i2(t2.i2) {}
  // NOTE: 加const是为了只读取成员变量的值，不能修改值

  int i;
  int i2;
};

int main() {
  CTest t1;
  CPPTest t2( 1,2 ); // NOTE: C++中如果未初始化对象，会调用构造函数，但是默认的构造函数是什么都不做的
  std::cout << t1.i << std::endl << t1.i2 << std::endl;
  std::cout << t2.i << std::endl << t2.i2 << std::endl;
  return 0;
}

```

构造函数的类型

    1. 普通构造函数：
    
    2. 复制构造函数：

> 用另一个对象来初始化对象对应内存

    3. 移动构造函数：

> 也是用一个对象来初始化对象

    4. 默认构造函数：

> 当类中没有构造函数是，编译器会为该类生成一个默认的构造函数，在最普通的类中，默认构造函数什么都没做，对象对应的内存没有初始化

总结： 构造函数就是 C++提供的`必须有的`在对象创建时初始化对象的方法

> 默认什么也不做也是一种初始化方式

3. 析构函数

当类对象被销毁时，就会调用析构函数。栈上对象的销毁时机就是函数栈销毁时

堆上的对象销毁时机就是该堆内存被手动释放是，如果用`new`申请的这块堆内存，那调用`delete`销毁这块内存是就会调用析构函数

![Screenshot_20230222_112347_com.baidu.netdisk.jpg](https://img1.imgtp.com/2023/02/22/gXavxkxC.jpg)

```c++
#include <iostream>

// 仿C写法
struct CTest { // NOTE: C语言是无法在定义对象是将里面的数据初始化的
  int i;
  int i2;
};

struct CPPTest {
public:
  CPPTest(int i_, int i2_ , int i3) : i(i_), i2(i2_) , pi(new int(i3)) {}

  //复制构造函数
  CPPTest(const CPPTest& t2) :i(t2.i) , i2(t2.i2) , pi(new int (*t2.pi)) {}
  // NOTE: 加const是为了只读取成员变量的值，不能修改值


  //模拟默认构造函数
  // CPPTest(){}



  //析构函数
  ~CPPTest() {

    delete pi;
  } // NOTE:因为析构函数不带参数，所以无法重载

  int i;
  int i2;

  int* pi;
};

int main() {
  CTest t1;
  CPPTest t2( 1,2 , 3); // NOTE: C++中如果未初始化对象，会调用构造函数，但是默认的构造函数是什么都不做的
  std::cout << t1.i << std::endl << t1.i2 << std::endl;
  std::cout << t2.i << std::endl << t2.i2 << std::endl;


  CPPTest* pt2 = new CPPTest(1 , 2 , 3); // NOTE:调用在堆上

  delete pt2;
  return 0;
}

```

总结：当类对象销毁时有一些我们必须手动操作的步骤时，析构函数就排上了用场。所以，几乎所有的类我们都要写构造函数，析构函数未必需要

### 2. 类的权限修饰

1. 访问限定符

C++ 通过 public、protected、private 三个关键字来控制成员变量和成员函数的访问权限(也成为可见性)，分别表示:公有的、受保护的、私有的

- public
- protected
- private

```c++

class Base
{
  public:
  protected:
  private:
};


```

2. 访问权限

> 能不能使用该类中的成员

一般地，在类的内部，无论成员被声明为哪种，都是可以互相访问的；但在类的外部，如通过类的对象，则只能访问 public 属性的成员，不能访问 protected、private 属性的成员。

> 对象(object)是类(class)的一个实例(instance)
> 具体如下：

- public: 可以被该类中的函数、子类的函数、友元函数访问，也可以由该类的对象访问

- protected: 可以被该类中的函数、子类的函数、友元函数访问，但不可以由该类的对象访问

- private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象访问

> private 关键字的作用在于更好地隐藏类的实现

3. 注意事项

   1. 如果声明不写`public、protected、private`,则默认为`private`
   2. 声明`public、protected、private`的顺序可以任意
   3. 在一个类中，`public、protected、private`可以出现多次，每个限定符的有效范围到出现另一个限定符或类结束为止。但为了使程序清晰，应该每种限定符只出现一次

### 3. "This" , 常成员函数与常对象

#### this 关键字

1. 什么是 this

编译器将 this 解释为指向函数所作用的对象的指针

```C++
#include <iostream>

class Test {
private:
  std::string name;
  unsigned old;

public:
  Test(const std::string &name_, unsigned old_);
  ~Test();

  void outPut() const {
    // std::cout << "name = " << name << " old = " << old;
    std::cout << "name = " << this->name << " old = " << this->old;
  }
};

Test::Test(const std::string &name_, unsigned old_) : name(name_), old(old_) {}

Test::~Test() {}

int main() {
  Test test("cxy", 100);
  test.outPut();
  return 0;
}

```

当然，这么说并非完全正确，this 是一个关键字，只是我们将它当做指针理解罢了

#### 常成员函数、常对象

> 在大型程序中，尽量加上 const 关键字可以减少很多不必要的错误

1. 常成员函数就是无法修改成员变量的函数，可以理解为将 this 指针指向对象用 const 修饰的函数
2. 常对象就是用 const 修饰的对象，定义好之后就再也不需要修改成员变量的值了

常成员函数注意事项

> 因为类成员函数已将 this 指针省略了，只能在函数后面加 const 关键字来实现无法修改类成员变量的功能了

```c++
  void outPut()const { std::cout << this->name << ' ' << this->old << std::endl; }
```

1. 注意: 常函数无法调用普通函数，否则常函数的这个“常”字还有什么用？
2. 成员函数能写作常成员就尽量写作常成员函数，可以减少出错几率
3. 同名的常成员函数和普通成员函数是可以重载的，常量对象会优先调用常成员函数，普通对象会优先调用普通成员函数

```c++
#include <iostream>

class Test {
public:
  Test(const std::string &name_, unsigned old);
  ~Test();
  void outPut() const {
    std::cout << this->name << ' ' << this->old << std::endl;
  }
  void outPut() { std::cout << this->name << ' ' << this->old << std::endl; }

private:
  std::string name;
  unsigned old;
};

Test::Test(const std::string &name_, unsigned old_) : name(name_), old(old_) {}

Test::~Test() {}

int main() {
  const Test test("cxy", 1010);
  test.outPut();
  Test test2("yxc" , 1000);
  test2.outPut();
  return 0;
}

```

常对象注意事项

1. 常对象不能调用普通函数
2. 常函数在大型程序中真的很重要，很多时候我们都需要创建好就不再改变的对象，不要怕麻烦

总结： 常成员函数和常对象要多用

### inline, mutable, default, delete

> `inline`和`mutable`只要知道就好
> `default`和`delete`关键字是需要掌握的

#### 1. inline 关键字

1. inline 关键字有什么作用

   1. 在函数声明或者定义中函数返回类型加上关键字`inline`就可以把函数指定为内联函数，关键字`inline`必须与函数定义放在一起才能使函数成为内联，仅仅`inline`放在函数声明前不起任何作用
   2. 内联函数的作用，普通函数在调用时需要给函数分配栈空间以供函数执行，压栈等操作会影响成员运行效率，于是 C++提供了内联函数将函数体放到需要调用函数的地方，用空间换效率

```c++
#include <iostream>

class Test {
public:
  void outPut();
};

inline void Test::outPut() { std::cout << "hello world" << std::endl; }

int main() {

  Test test;
  test.outPut();
  return 0;
}

```

2. inline 关键字的注意事项

inline 关键字只是一个建议，开发者建议编译器将成员函数当做内联函数，一般适合搞内联情况编译器都会采纳建议

3. inline 关键字总结

使用 inline 关键字就是一种提高效率，但加大编译后文件大的方式，现在很少用了

#### 2. mutable 关键字

> 一般来说只有在统计函数调用次数才会用到

1. mutable 关键字的作用

   1. `mutable`意为可变的，与 const 相对，被`mutable`修饰的成员变量，永远处于可变的状态，即使处于一个常函数中，该变量也可以被更改

```c++
#include <iostream>

class Test {

public:
  void outPut() const;
  mutable unsigned outPutCallcnt = 0;
};

void Test::outPut() const {
  ++outPutCallcnt;
  std::cout << "hello world" << std::endl;
}

int main() {
  Test test;
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();
  test.outPut();

  std::cout << test.outPutCallcnt << std::endl;

  return 0;
}

```

2. mutable 关键字的注意事项

   1. `mutable`是一种万不得以的写法，但一个程序不得不使用`mutable`关键字时，可以认为这部分程序是一个糟糕的设计
   2. `mutable`不能修饰静态成员变量和常成员变量

3. 总结

`mutalbe`关键字是一种没有办法的办法，设计时应该尽量避免

#### 3. default 关键字

1. default 关键字的作用

   1. 在编译时不会生成默认构造函数便于书写
   2. 也可以对默认复制构造函数，默认的复制运算符和默认的析构函数使用，表示使用的是系统默认提供的函数，可以使代码更加明显
   3. 现代 C++中，哪怕没有构造函数，也推荐将构造函数用`default`关键字来标记，可以让代码看起来更加直观，方便

```c++
#include <iostream>

class Test {
public:
  Test(unsigned old_) : old(old_) {}
  Test(const Test& test) = default;
  Test() = default;
  Test& operator=(const Test& test) = default;
  ~Test() = default;

  unsigned old;
};


int main() {


  return 0;
}

```

2. 总结

`default`关键字还是推荐使用，在现代 C++代码中，如果需要使用一些默认的函数，推荐用`default`标记出来

#### 4. delete 关键字

1. delete 关键字的作用：C++会为程序生成默认构造函数，默认复制构造函数，默认重载赋值运算符  
   很多情况下，我们并不希望这些默认的函数被生成，在 C++11 以前，只能有将此函数声明为私有函数或是将函数只声明不定义两种方式

```c++
#include <iostream>

class Test {
public:
  Test(unsigned old_) : old(old_) {}
  Test(const Test& test) = delete;
  Test() = delete;
  Test& operator=(const Test& test) = delete;
  ~Test() = delete;

  unsigned old;
};


int main() {


  return 0;
}

```

2. 总结

`delete`关键字还是推荐使用的，在现代 C++代码中，如果不希望一些函数默认生成，就用 delete 表示，这个功能还是很有用的，例如单例模式中

### 友元类和友元函数

#### 1. 友元的介绍，友元就是可以让另一个类或函数访问私有成员的简单写法

```c++
#include <iostream>
class Test {
  friend class Test2;
  friend void outPut(const Test &test);

private:
  std::string name;
  unsigned old;
};

class Test2 {
public:
  void outPut(const Test &test) {
    std::cout << test.name << ' ' << test.old << std::endl;
  }
};

void outPut(const Test &test) {
  std::cout << test.name << ' ' << test.old << std::endl;
}

int main() { return 0; }

```

#### 2. 注意

1. 友元函数会破坏封装性，一般不推荐使用，所带的方便写几个接口函数就解决了
2. `某些运算符的重载必须用到友元的功能，这才是友元的真正用途`

总结: 友元平常并不推荐使用，不要再纠结友元的语法，只要可以用友元写出必须用友元的重载运算符的就可以了

### (\*\*)重载运算符

#### 1. 重载运算符的作用

1. 很多时候我们想让类对象也能像其他基础类型的对象一样进行基础操作，比如"+", "-", "\*" ,"/", 也可以使用某些运算符"=" , ">>" ，"<<", "()" , "{}", 但是一般类即使编译器可以识别这些运算符，类对象也无法对这些运算符做出应对，我们必须对类对象定义处理这些运算符的方式

2. C++提供了定义这些行为的方式，就是`operator`运算符来定义运算符的行为，`operator`是一个关键字，告诉编译器我要重载运算符了

#### 注意

1. 我们只能重载 C++已有的运算符，所以无法将`**`这个运算符定义为指数的形式，因为 C++根本没有`**`这个运算符

2. C++重载运算符不能改变运算符的元数，`元数`这个概念就是指一个运算符对应的对象数量，比如`+`必须为`a + b` ,也就是说`+`必须有两个对象,那么`+`就是二元运算符。比如`++`运算符，就必须写为`a++`，也就是一元运算符

#### 例子

1. 一元运算符重载

```c++
++ ， --；
[]
()
>>， <<
```

```c++
#include <iostream>
#include <string>
#include <vector>

class Test {

  friend std::ostream &operator<<(std::ostream &os, const Test &test);
  friend std::istream &operator>>(std::istream &is, Test &test);

public:
  unsigned cnt = 0;
  std::vector<int> st{1, 2, 3, 4, 5, 6, 7, 8};
  std::string str;
  std::string name;

  void operator++() { ++cnt; }
  void operator--() { --cnt; }
  void operator()() const { std::cout << "hello world" << std::endl; }
  void operator()(const std::string &str) { std::cout << str << std::endl; }
  int operator[](unsigned i) {
    if (i >= 0 && i < st.size())
      return st[i];
    return 0;
  }
};

std::ostream &operator<<(std::ostream &os, const Test &test) {
  os << test.name << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, Test test) {
  is >> test.name;
  return is;
}

int main() {
  Test test;
  ++test;
  std::cout << test.cnt << std::endl;
  --test;
  std::cout << test.cnt << std::endl;

  for (int i = 0; i < test.st.size(); i++)
    std::cout << test[i] << ' ';

  std::cout << std::endl;

  test();
  test("cxy");
  std::cin >> test.name;
  std::cout << test.name;


  return 0;
}

```

2. 二元重载运算符

```c++
+ , - , * , /
=
> ， < , ==

至于三目运算符"?:" 不能重载

注意: “=”类会默认重载，如果不需要可以用"delete"关键字进行修饰

```

```c++
#include <iostream>
#include <string>
#include <vector>

class Test {

public:
  unsigned cnt = 0;

  Test operator+(const Test &test) {
    cnt += test.cnt;
    return *this;
  }
  Test &operator=(const Test &test) {
    if (this == &test)
      return *this;

    cnt = test.cnt;
    return *this;
  }

  bool operator<(const Test &test) { return cnt < test.cnt; }
  bool operator>(const Test &test) { return cnt > test.cnt; }
  bool operator==(const Test &test) { return cnt == test.cnt; }
};

int main() {
  Test test;
  // std::cout << test.cnt << std::endl;
  test.cnt = 20;
  Test test2;
  Test test3 = test + test2;
  std::cout << test3.cnt << std::endl;

  return 0;
}
```

#### 总结

重载运算符非常重要，C++类中几乎要定义各种各样的重载运算符

### (\*\*\*)类的继承

C++面向对象的三大特性:分装、继承、多台。分装就是类的管理

#### 介绍

C++非继承的类相互是没有关系的，假设现在需要设计医生、教师、公务员三个类，需要定义很多重复的内容而且相互没有关联，调用也没有规律，如果这还算好，那一个游戏有几千件物品，调用时也要写几千个函数，于是继承能力就应运而生了

#### 原理

C++继承原理: C++的继承可以理解为在创建子类成员把变量之前先创建父类的成员变量，实际上，C 语言就是这么模仿出来的

```c++
#include <iostream>
#include <string>

class Spear {
protected:
  std::string name;
  std::string icon;

public:
  Spear(const std::string &name_, const std::string &icon_)
      : name(name_), icon(icon_) {
    std::cout << "Spear()" << std::endl;
  }
  ~Spear() {
    std::cout << "Delete Spear" << std::endl;
  }
};

class FireSpear : public Spear {
private:
  int i;


public:
  FireSpear(const std::string &name_, const std::string &icon_, int i_)
      : Spear(name_, icon_), i(i_) { // NOTE: 先调用父类的构造函数，初始化父类的部分,然后调用自己的构造函数，初始化自己的部分
    std::cout << "FireSpear()" << std::endl;
  }
  void outPut() { std::cout << name << std::endl; }
  ~FireSpear() {
    std::cout << "Delete FireSpear" << std::endl;
  }
};

int main() {

  FireSpear firespear("fire", "iron", 10);
  // Spear *pFather = new Spear("father" , "10"); // NOTE:可以创建父类对象指针指向自己
  // Spear *pSon = new FireSpear("son" , "10" , 10); // NOTE: 也可以创建父类对象指针指向子类对象

  return 0;
}

```

#### 注意事项

1. C++子类对象的构造过程，先调用父类的构造函数，在调用子类的构造函数，也就是说先初始化父类的成员，再初始化子类的成员

2. 若父类没有默认的构造函数，子类的构造函数又未调用父类的构造函数，则无法编译

3. C++子类对象的析构过程，先调用父类的析构函数，再调用子类的析构函数

#### 总结

面向对象的三大特性的继承就这么简单，很多人觉得类继承很复杂，其实完全不是，这样的，只要明白子类在内存上其实就相当于把父类的成员变量放在子类的成员变量前面罢了，构造和析构过程也是为了这个机制而设计的

### (\*\*)虚函数及其实现原理， overide 关键字

#### 介绍

1. 虚函数就是面向对象的第三大特点`多态`，多态非常重要，它完美解决了上面游戏装备设计的难题，我们可以只设计一个函数，函数参数是基类指针，就可以调用子类的功能。比如射击游戏，所有的枪都继承自一个枪的基类，人类只要有一个开枪的函数就可以实现所有枪打出不同的子弹

2. 父类指针可以指向子类对象，这个是自然而然的，因为子类对象的内存前面就是父类成员，类型完全匹配

3. 当父类指针指向子类对象，且子类重写父类的某一函数时，父类指针调用该函数，就会产生一下可能

   1. 该函数为虚函数：父类指针调用的是子类的成员函数
   2. 该函数不是虚函数：父类指针调用的是父类的成员函数

```c++
#include <iostream>
#include <string>

class Spear {
protected:
  std::string name;
  std::string icon;

public:
  Spear(const std::string &name_, const std::string &icon_)
      : name(name_), icon(icon_) {
    std::cout << "Spear()" << std::endl;
  }

  virtual void openFire() const { std::cout << "Spear OpenFire!" << std::endl; }

  virtual ~Spear() { std::cout << "Delete Spear" << std::endl; } // NOTE: 父类的析构函数必须为虚函数，才能调用子类的析构函数
};

class FireSpear : public Spear {
private:
  int i;

public:
  FireSpear(const std::string &name_, const std::string &icon_, int i_)
      : Spear(name_, icon_), i(i_) {
    std::cout << "FireSpear()" << std::endl;
  }
  void outPut() { std::cout << name << std::endl; }

  virtual void openFire() const override { // NOTE: 防止开发人员将函数名写错，所以加上override关键字以防万一
    // NOTE: 如果将子类的virtual关键字删掉，
    // NOTE: 父类指针依旧会调用该函数，因为父类的该函数有virtual关键字，在编译时子类也会自动加上virtual关键字
    std::cout << "FireSpear OpenFire!" << std::endl;
  }

  ~FireSpear() { std::cout << "Delete FireSpear" << std::endl; }
};

void openFire(const Spear *pFather) {
  pFather->openFire();
  delete pFather;
}

int main() {

  openFire(new FireSpear("Fire" , "flame" , 10));
  // NOTE: 加了virtual关键字后，多态，父类的指针可以调用子类的函数
  // NOTE:  不加virtual关键字时，静态绑定，在编译时就能确定函数的地址


  return 0;
}
```

#### 注意事项

1. 子父类的虚函数必须`完全相同`，为了防止开发人员一不小心将函数写错，于是有了 override 关键字

2. (\*)父类的析构函数必须为虚函数，这一点很重要，当父类对象指向子类对象时，容易使独属于子类的内存泄露，会造成内存泄漏的严重问题

3. override 关键字的作用

4. 虚函数实现多态的原理介绍

   1. 静态绑定和动态绑定

      1. 静态绑定：程序在编译时就已经确定了函数的地址，比如非虚函数就是静态绑定
      2. 动态绑定：程序在编译时确定的是程序寻找函数地址的方法，只有程序运行时才可以真正确定程序的地址，比如虚函数就是动态绑定

   2. 虚函数是如何实现动态绑定的呢？

      1. 每个有虚函数的类都会有一个虚函数表，对象其实就是指向虚函数的指针，编译时编译器只告诉了程序在运行时查找虚函数表的对应函数。每个类都会有自己的虚函数，所以当父类指针引用的是子类虚函数表时，自然调用的就是子类的函数

#### 总结

虚函数是 C++类的重要特性之一，很简单，但使用频率非常高，至于如何实现也要掌握

### 静态成员变量与静态成员函数

#### 1. 静态成员变量

1. 在编译期就已经在静态变量区明确了地址，所以生命周期为程序开始到程序结束，作用范围与普通的成员变量相同。这些对于类的静态成员变量同样适用

2. 类的静态成员变量因为创建在静态变量区，所以直接属于类，也就是我们可以直接通过类名来调用，当然通过对象来调用也行

```c++
#include <iostream>
#include <string>

class Test {
private:
  static unsigned i;
public:
  static unsigned getI() {return i; } // NOTE: 为静态成员变量服务，保护封装性
};

unsigned Test::i = 20; // NOTE: 一定要在类外初始化

int main() {

  Test test;

  std::cout << test.getI() << std::endl; // NOTE: 通过对象来调用静态成员变量
  // std::cout << Test::i << std::endl; // NOTE: 通过类名来调用静态成员变量
  return 0;
}

```

#### 2. 静态成员变量的注意事项

静态成员变量必须在类外进行初始化，否则会报未定义的错误，不能用构造函数进行初始化，因为静态成员变量在静态变量区，只有一份，而且静态成员变量在编译期就要被创建，成员函数那都是运行期的事情了

#### 3. 静态成员变量的特点

静态成员函数就是为静态成员变量设计的，就是为了维持封装性

### (\*) 纯虚函数

#### 介绍

1. 之前枪械射击的例子，基础的枪类没有对应的对象，它唯一的作用就是被子类继承
2. 基类的`openfire`函数实现过程有意义吗？没有，它就是用来被重写的
3. 所以纯虚函数的语法就诞生了，只要将一个虚函数写为纯虚函数，那么该类将被认为无实际意义的类，无法产生对象，纯虚函数也不用去写实际部分，写了编译器也会自动忽略

```c++
#include <iostream>
#include <string>

class Spear { // WARNING: 构造函数和析构函数不能省略，构造子类的时候要用的
protected:
  std::string name;
  std::string icon;

public:
  Spear(const std::string &name_, const std::string &icon_)
      : name(name_), icon(icon_) {
    std::cout << "Spear()" << std::endl;
  }

  virtual void openFire() const = 0; // NOTE: 只需要在虚函数后面赋值=0，这个函数就是纯虚函数，不需要函数实现过程，它就是个虚基类，虚基类无法产生对象

  virtual ~Spear() { std::cout << "Delete Spear" << std::endl; }
};

class FireSpear : public Spear {
private:
  int i;

public:
  FireSpear(const std::string &name_, const std::string &icon_, int i_)
      : Spear(name_, icon_), i(i_) {
    std::cout << "FireSpear()" << std::endl;
  }
  void outPut() { std::cout << name << std::endl; }

  virtual void openFire() const override {
    std::cout << "FireSpear OpenFire!" << std::endl;
  }

  ~FireSpear() { std::cout << "Delete FireSpear" << std::endl; }
};

void openFire(const Spear *pFather) {
  pFather->openFire();
  delete pFather;
}

int main() {

  openFire(new FireSpear("Fire" , "flame" , 10));
  // Spear *pSear = new Spear("awdjk" , "awdk");
  // pSear->openFire(); // NOTE: 这种对象没有任何意义

  return 0;
}
```

#### 总结

纯虚函数的特点就是语法简单，却经常使用，必会

### RTTI

#### 1. 介绍

1. RTTI(Run Time Type Identification) 即通过运行时类型识别，程序能够通过基类的指针或引用来检查这些指针或引用所指向的对象的实际派生类
2. C++为了支持多态，C++的指针或引用的类型可能与它实际指向的对象类型不相同，这是就需要 RTTI 来判断类的实际类型，RTTI 是 C++判断指针或引用实际类型的唯一方式

#### 2. 使用场景

1. 异常处理： 这是 RTTI 主要使用场景，具体作用放在异常处理那一章
2. IO 操作：IO 章节

#### 3. 使用方式

> 使用过程就两个函数

1. `typeid函数`： `typeid函数`返回的一个叫做`type_info`的结构体，该结构体包括了所指向对象的实际信息，其中`name()函数`就可以返回函数的真实名称，`type_info`结构体其他函数没什么用

2. `dynamic_cast()函数`：C++提供的将父类指针转化为子类指针的函数

```c++
#include <iostream>
#include <string>

class Spear {
protected:
  std::string name;
  std::string icon;

public:
  Spear(const std::string &name_, const std::string &icon_)
      : name(name_), icon(icon_) {
    std::cout << "Spear()" << std::endl;
  }

  virtual void openFire() const { std::cout << "Spear OpenFire!" << std::endl; }

  virtual ~Spear() { std::cout << "Delete Spear" << std::endl; }
};

class FireSpear : public Spear {
private:
  int i;

public:
  FireSpear(const std::string &name_, const std::string &icon_, int i_)
      : Spear(name_, icon_), i(i_) {
    std::cout << "FireSpear()" << std::endl;
  }
  void outPut() { std::cout << name << std::endl; }

  virtual void openFire() const override {
    std::cout << "FireSpear OpenFire!" << std::endl;
  }

  ~FireSpear() { std::cout << "Delete FireSpear" << std::endl; }
};

void openFire(const Spear *pFather) {
  pFather->openFire();
  delete pFather;
}

int main() {

  Spear *pSpear = new FireSpear("ad" , "awdw" , 30);
  std::cout << typeid(*pSpear).name() << std::endl;

  // NOTE: 由于name返回的是一个const char *指针，"9FireSpear"也是一个const char *，要保证指针的地址一样，所以得用string存起来
  if(std::string (typeid(*pSpear).name()) == "9FireSpear") {
    FireSpear *pFireSpear = dynamic_cast<FireSpear*>(pSpear);
    if(pFireSpear)
      std::cout << "cast FireSpear success" << std::endl;
  }

  delete pSpear;


  return 0;
}

```

#### 4. 注意事项

当使用`typeid函数`时，父类和子类必须有`虚函数`

> 父类有了虚函数，子类自然也有虚函数，否则类型会判断出错

#### 5. 总结

就是 C++在运行阶段判断对象实际类型的唯一方式

### 多继承

> 了解就行

#### 1. 多继承的概念

就是一个类同时继承多个类，在内存上，该类对象前面依次为第一个继承的类，第二个继承的类，依次类推

```c++
#include <iostream>
#include <string>


// NOTE: 构造函数的运行过程是从第一个祖宗到儿子再到孙子，析构函数则是反过来
class Base1 {
public:
  Base1(int base1I_) : base1I(base1I_) { std::cout << "base1" << std::endl; }
  ~Base1() {
    std::cout << "Bye Base1" << std::endl;
  }
protected:
  int base1I;
};

class Base2 {
public:
  Base2(int base2I_) : base2I(base2I_) { std::cout << "base2" << std::endl; }
  ~Base2() {
    std::cout << "Bye Base2" << std::endl;
  }

protected:
  int base2I;
};

class HENCE : public Base1, public Base2 {

public:
  HENCE(int base1I_, int base2I_, int i_)
      : Base1(base1I_), Base2(base2I_), i(i_) {
    std::cout << "HENCE" << std::endl;
  }
  ~HENCE() {
    std::cout << "Bye HENCE" << std::endl;
  }

private:
  int i;
};

int main() {

  HENCE hence(10, 20, 30);
  return 0;
}

```

#### 2. 多继承的注意点

1. 多继承最需要注意的点就是重复继承的问题
2. 多继承会使整个程序设计更加复杂，平常不推荐使用

#### 3. 总结

多继承这个语法虽然在某些情况下是代码写起来更加简洁，但会使程序更加复杂难懂，一般来说除了接口模式以外不推荐使用

### 虚继承及其实现原理

#### 概念

虚继承就是为了避免多重继承时产生的二义性问题

#### 实现原理介绍

1. 使用了虚继承的类会有一个虚继承表，表中存放了父类所有成员变量相对于类的偏移地址

2. 当`C`类同时继承`B1`和`B2`类时，每继承一个就会用虚继承表进行比对，发现该变量在虚继承表中偏移地址相同，就只会继承一份。

#### 总结

这个语法就是典型的语法简单，但在游戏开发领域经常使用的语法，其他领域使用频率会低一点

### (\*\*)移动构造函数与移动运算符

#### 1. 对象移动的概念

1. 对一个体积比较大的类进行大量的拷贝操作是非常消耗性能的，因此 C++11 中加入了`对象移动`的操作
2. 所谓的对象移动，其实就是把该对象所占据的内存空间的访问权限转移给另一个对象，比如一块内存原本属于`A`，在进行“移动语义”后，这块内存就属于`B`了

#### 2. 移动语义为什么可以提高运行效率

因为我们的各种操作会经常进行大量的“复制构造”，“赋值运算”操作，这两个操作非常耗时间。移动构造是直接转移权限，效率就提高了

注意：

```
在进行转移操作后，被转移的对象就不能继续使用了，所以对象移动一般都是对临时对象进行操作

因为临时对象就要被销毁了
```

```c++
#include <iostream>
#include <string.h>
#include <string>

class Test {
public:
  //NOTE: 不需要重新new一遍来消耗时间
  Test() = default;

  // Test(const Test &test) {
  //
  //   if (test.str) {
  //     str = new char[strlen(str) + 1](); // strlen在统计的时候，不会算结束符
  //     // strcpy()(str , strlen(test.str) + 1 , test.str); // WARNING: it doesn't
  //     // work
  //     strcpy(str, test.str);
  //   } else {
  //     str = nullptr;
  //   }
  // }

  Test(Test &&test) {
    if (test.str) {
      str = test.str;
      test.str = nullptr;
    } else {
      str = nullptr;
    }
  }

  // Test &operator=(const Test &test) {
  //   if (this == &test)
  //     return *this;
  //   if (str) {
  //     delete[] str;
  //     str = nullptr;
  //   }
  //   if (test.str) {
  //     str = new char[strlen(str) + 1]();
  //     strcpy(str, test.str);
  //   } else {
  //     str = nullptr;
  //   }
  //   return *this;
  // }
  Test &operator=(Test &&test) { // NOTE:不要加const，后面要修改
  //因为用右值引用函数参数就是为了让其绑定到一个右值上去的！就是说这个右值引用是一定要变的，
  //但是一旦加了const就无法改变
    if (this == &test)
      return *this;

    if (str) {
      delete[] str;
      str = nullptr;
    }
    if (test.str) {
      str = test.str;
      test.str = nullptr;
    } else {
      str = nullptr;
    }
    return *this;
  }

private:
  char *str = nullptr;
};

Test makeTest() {

  Test t;
  return t;
}

int main() {

  Test t = makeTest();

  return 0;
}

```

#### 3. 默认移动构造函数和默认移动赋值运算符

会默认生成移动构造函数和移动赋值运算符的条件 ：

1. 只有一个类没有定义任何自己版本的拷贝操作（拷贝构造、拷贝赋值运算符），且类的每个非静态成员都可以移动，系统才会合成

2. 可以移动的意思是可以就行移动构造、移动赋值。所有的基础类型都是可以移动的。有移动语义的类也是可以移动的

---

## 函数重载 overlord

1. 函数名相同
2. 参数不同

Example:

```c++
#include<iostream>
using namespace std;

void func(int x , int y)
{
    cout << "func(int x , int y)" << endl;
}

void func()
{
    cout << "func()" << endl;
}

void func(double x , double y)
{
    cout << "func(double x , double y)" << endl;
}



// NOTE : 函数重载由函数名以及参数(个数、类型)来决定，跟返回值没有关系
//
// int func(int x , int y)
// {
//     return x + y;
// }

int main()
{


    return 0;
}


```

如何区分调用不同的重载函数

> 通过参数

```c++
#include<iostream>
using namespace std;

void func(int x , int y)
{
    cout << "func(int x , int y)" << endl;
}

void func()
{
    cout << "func()" << endl;
}

void func(double x , double y)
{
    cout << "func(double x , double y)" << endl;
}



// NOTE : 函数重载由函数名以及参数(个数、类型)来决定，跟返回值没有关系
//
// int func(int x , int y)
// {
//     return x + y;
// }

int main()
{
    func(1 , 1);
    func();
    func(1.1 , 1.1);
    return 0;
}

```

结果：

```
func(int x , int y)
func()
func(double x , double y)
```

应用场景

- 需要使用同一个函数但是数据的类型不同，数量也不同

## 内联函数

1. 什么是内联函数

   > 用关键字 inline 修饰的函数就是内联函数。关键字在函数声明和定义的时候都要加上，不写系统还是会当成常规函数

2. 内联函数和一般函数的区别

   1. 内联函数比一般函数在前面多一个 inline 修饰符
   2. 内联函数是直接复制“镶嵌”到主函数中去的，就是将内联函数的代码直接放在内联函数的位置上，这与一般函数不同，
      主函数在调用一般函数的时候，是指令跳转到被调用函数的入口地址，执行完被调用函数后，指令再跳转回主函数上继续执行后面的代码；
      而由于内联函数是将函数的代码直接放在了函数的位置上，所以没有指令跳转，指令按顺序执行
   3. 一般函数的代码段只有一份，放在内存中的某个位置上，当程序调用时，指令就跳转过来；当下一次程序调用时，指令又跳转过来；而内联函数就是程序中调用几次内联函数，内联函数的代码
      就会复制几份放在对应的位置上
   4. 内联函数一般在==头文件==中定义，而一般函数在头文件中声明，在 cpp 中定义

3. 利与弊

- 利：避免了指令的来回跳转，加快程序执行速度
- 弊：代码被多次复制，增加了代码量，占用了更多的内存

4. 什么时候使用内联函数

   1. 函数本身内容比较少，代码比较短，函数功能相对简
   2. 函数被调用得频繁，不如循环中的函数

5. 什么时候不能使用内联函数

   1. 函数代码量多，功能复杂，体积庞大。对于这种函数就算加上 inline 修饰符，系统也不一定会相应，可能还是会当成一般函数处理
   2. 递归函数不能使用内联函数

6. 内联函数比宏更强大

看一段代码：

```c++
#include <iostream>
using namespace std;

#define SUM(x) x *x

inline int fun(int x) { return x * x; }

int main() {
  int a = SUM(2 + 3);
  int b = fun(2 + 3);

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  return 0;
}

```

执行结果:

```c++
a = 11;
b = 25;
```

---

为什么通过宏执行的结果是 11？

- 宏比较机械和简单，只是将传入的参数直接放上去就执行
- 所以 int a = SUM(2 + 3) 实际上就相当于$a = 2 + 3 \times 2 + 3$；由于乘法的优先级更高，所以得到 a 的值为 11；而在内联函数中，传入的参数是 5，所以得到的是 25

为了得到正确结果，宏应该改变为

```c++
#define SUM(x) ((x) * (x))
```

7. 类与内联函数

   1. 类内定义的函数都是内联函数，不管是否有 inline 修饰符
   2. 函数声明在类内，但定义在类外的看是否有 inline 修饰符，如果有就是内联函数，否则不是

---

## new 关键字 (\*)

### 1. new 关键字是 C++用来动态分配内存的主要方式

> new 可以直接分配单个变量的内存，也可分配数组

1. 在分配单个对象的内存时
   - 当单个对象是普通变量时，可以分配对应的内存
   - 当对象是类对象时，会调用构造函数，如果没有对应的构造函数，就会报错

代码如下：

```c++
#include<iostream>

int main()
{
    int* pi = new int(100);//如果不分配一个值的话，那么这个指针在内存中是未定义的，值也是随机的
    std::cout << *pi << std::endl;

    std::string *pString = new std::string("hello world");
    std::cout << *pString << std::endl;
    delete pString;
    delete pi;
    return 0;
}
```

2. 在分配数组对象内存时：
   - 对于普通变量，可以使用"()"将所有对象初始化为 0
   - 对于类对象，有没有"()"都一样，均默认使用构造函数，如果没有默认构造函数，就会报错

```c++
#include<iostream>

int main()
{

    int *pi = new int[100]();

    for(int i = 0; i < 100 ; i ++)
        std::cout << pi[i] << std::endl;

    delete[] pi;
    //delete pi;// ERROR : 不加括号会导致内存泄漏


    std::string* pString = new std::string[100]();
    std::cout << pString[20] << std::endl;

    delete[] pString;



    return 0;
}

```

### 2. 内存泄露（常见 bug）

1. 内存泄露的后果

   - 内存泄露会导致堆内存的逐渐被占用，最终内存用完程序崩溃。常见的情况就是项目测试没问题，上线几天就炸了。然后就会非常麻烦，排查困难，损失很大。
   - 内存泄露是最严重的错误之一，程序不怕报错，就怕一开始运行的好好的，突然就出现了莫名其妙的错误。

2. 检测工具使用

[valgrind](https://zhuanlan.zhihu.com/p/75416381)

3. 解决方法

   1. 智能指针
   2. 异常处理

---

## const 关键字

使编译器将变量视为常量，与真正的变量有着本质的区别

```c++
#include <iostream>

int main() {
  int i = 100;
  const int i2 = 10;
  // 100 , 20  "abcde"

  return 0;
}

```

1. 真正的常量存储在常量区或代码区，比如"abcde"这个字符串就存储在常量区，而“3”，“100”这些数字就存储在代码区，这些都是真正的常量无法用任何方式修改

2. const 修饰的变量仍然存储在堆区或栈区中，从内存分布的角度讲，和普通变量没有区别。const 修饰的变量并非不可更改，C++本身就提供了`mutable`关键字用来修改 const 修饰的变量，从汇编的角度讲，const 修饰的变量也是可以修改的

## (\*\*)auto 关键字

关于输出 auto 推断的变量类型 -- boost 库

```c++
#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

int main()
{
    auto i = 100;
    std::cout << type_id_with_cvr<decltype(i)>().pretty_name() << std::endl;

    return 0;
}

```

需要注意的点

1. auto 只能推断出类型，引用不是类型，所以 auto 无法推断出引用，要使用引用只能自己加引用符号
2. auto 关键字在推断引用的类型时:会直接将引用替换为引用指向的对象。其实引用一直是这样的，引用不是对象，任何使用引用的地方都可以直接替换成引用指向的对象。

```c++
#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

int main()
{
    const int i = 100;
    const int& refi = i;
    auto i2 = refi;// 其实i2直接指向i
    std::cout << type_id_with_cvr<decltype(i2)>().pretty_name() << std::endl;

    return 0;
}

```

3. auto 关键字在推断类型时，如果没有引用符号，会忽略值类型的 const 修饰，而保留修饰指向对象的 const，典型的就是指针。

```c++
#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

int main()
{

    int i = 100;
    int a = 120;
    const int* const pi = &i;
    auto i2 = pi;// const int*
    i2 = &a;
    std::cout << type_id_with_cvr<decltype(i2)>().pretty_name() << std::endl;
    std::cout << *i2 << std::endl;
    // const int i = 100;
    // auto i2 = i;
    // std::cout << type_id_with_cvr<decltype(i2)>().pretty_name() << std::endl;
    return 0;
}

```

4. auto 关键字在推断类型时，如果有了引用符号，那么值类型的 const 和修饰指向对象的 const 都会保留。

```c++

#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

int main()
{

    int i = 100;
    const int* const pi = &i;
    auto& i2 = pi;
    std::cout << type_id_with_cvr<decltype(i2)>().pretty_name() << std::endl;
    return 0;
}
```

5. 当然，我们可以在 auto 前面加上 const，这样永远都有 const 的含义。

6. auto 不会影响编译速度，甚至会加快编译速度。因为编译器在处理 XX a = b 时，当 XX 是传统类型时，编译期需要检查 b 的类型是否可以转化为 XX。当 XX 为 auto 时，编译期可以按照 b 的类型直接给定变量 a 的类型，所以效率相差不大，甚至反而还有提升。

7. （\*）最重要的一点，就是 auto 不要滥用，对于一些自己不明确的地方不要乱用 auto，否则很可能出现事与愿违的结果，使用类型应该安全为先。

8. （\*）auto 主要用在与模板相关的代码中，一些简单的变量使用模板常常导致可读性下降，经验不足还会导致安全性问题。

```c++
#include <iostream>
#include <vector>
using namespace std;

vector<int> A;

int main() {
  int n = 5;
  while (n--) {
    int x;
    cin >> x;
    A.push_back(x);
  }

  for (vector<int>::iterator i = A.begin(); i != A.end(); i++)
    cout << *i << endl;// 可以用auto来代替vector<int>::iterator

  return 0;
}

```

## decltye关键字

- auto，用于通过一个表达式在编译时确定待定义的变量类型，auto所修饰的变量必须被初始化，编译器需要通过初始化来确定auto所代表的类型，即必须要定义变量。
- 若仅希望得到类型，而不需要（或不能）定于变量的时候那应该怎么办？C++11新增了`decltype`关键字，用来在编译时推导出一个表达式的类型。

```c++
decltype(exp)
//NOTE: exp表示一个表达式 expression
```

### 简单使用

```c++
#include <iostream>
#include <boost/type_index.hpp>

int main() {

    int c = 1;
    decltype(c) a = 10;

    std::cout << boost::typeindex::type_id<decltype(a)>().pretty_name() << std::endl;

    return 0;
}
```

在写一些函数引用绑定时进行辅助

```c++
#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

template<typename Container , typename Index>
decltype(auto) Func(Container& c , Index i) {
    if(i < c.size()) {
        return c[i];
    }
}

int main() {

    std::vector<int> a{1 , 4 , 5 , 3289};
    //NOTE: a[0] = 100 -> int&
    //但是bool类型不返回引用
    std::cout << boost::typeindex::type_id_with_cvr<decltype(Func(a , 2))>().pretty_name() << std::endl;
    return 0;
}

```

辅助万能引用

```c++
#include <iostream>
#include <vector>
#include <boost/type_index.hpp>
#include <utility>

template<typename Container , typename Index>
decltype(auto) Func(Container&& c , Index i) {
    //NOTE: 这样可以使得函数既可以处理左值，又可以处理右值
    return std::forward<Container>(c)[i];
}


int main() {

    std::vector<int> a{1 , 4 , 5 , 3289};
    //NOTE: a[0] = 100 -> int&
    //但是bool类型不返回引用
    std::cout << boost::typeindex::type_id_with_cvr<decltype(Func(std::vector<int>{1 , 398 , 58} , 2))>().pretty_name() << std::endl;
    return 0;
}

```

### decltype(auto)的一些区别

```c++
decltype(auto) f1() {
    int x = 0;
    ......

    return x //NOTE: decltype(x) is int, so f1 returns int
}

decltype(auto) f2() {
    int x = 0;
    .....
    return (x); //NOTE: decltype((x)) is int&, so f2 return int&
}



```

---

## 静态变量，指针和引用(\*)

> 变量的存储位置有三种，分别是静态变量区，栈区，堆区。

静态变量区在编译时就已经确定地址，存储全局变量与静态变量。

指针都是存储在栈上或堆上，不管在栈上还是堆上，都一定有一个地址。
本质上说，指针和普通变量没有区别。
在 32 位系统中，int 变量和指针都是 32 位。指针必须和“&”，“*”这两个符号一起使用才有意义。
&a 代表的 a 这个变量的地址，a 代表的 a 对应地址存储的值，*a 代表对应地址存储的值作为地址对应的值.

```c++
#include<iostream>


int main() {
  int n = 100;
  int *pa = &n;
  std::cout << *pa << std::endl;
  *pa = 110;
  std::cout << n << std::endl;
  return 0;
}

```

所以指针才可以灵活的操作内存，但这也带来了严重的副作用，比如指针加加减减就可以操作内存，所以引用被发明了，引用就是作用阉割的指针（可以视为“类型\*const”，所以引用必须上来就赋初值，不能设置为空），对引用来说，编译器不将其视作对象，操作引用相当于操作引用指向的对象。也就从根本是杜绝了引用篡改内存的能力。

```c++
#include <iostream>

int main() {

  int i = 10;
  int& re = i;

  std::cout << re << std::endl;
  re = 1111;
  std::cout << re << std::endl;
  std::cout << i << std::endl;
  return 0;
}

```

### 关于 const 和 pointer

常见表达式

```c++
1. const int p; // p is a int const. p是一个int型常量 这个很简单

2. const int *p; //p is a point to int const. p是一个指针，指向int型常量。即p是一个指向int型常量的指针。

3. int const *p; //与2相同 const int 和 int const 是一样的意思。《C++ primer》中采用第一种写法。

4. int * const p; // p is a const point to int. p是一个指向int的const指针

5. const int * const p; //p is a const point to int const. p是一个指向int型常量的const指针。

6. int const * const p; //同5
```

1. 指向常量的指针不能用于改变其所指对象的值

```c++
const double pi = 3.14; // pi是一个常量，不能改变它的值

const double *cptr = &pi; //cptr指向pi,注意这里的const不能丢，因为普通指针不能指向常量对象，即，不能用非const变量初始化指向常量的指针.

*cptr = 3.33;  //错误,试图改变所指对象的值。不能改变指针所指对象的值

cout << cptr << endl；//输出cptr的值

//虽然不能改变其所指对象的值，但是它可以指向别的常量对象
//这样的话 指针的值（也就是存放在指针中的那个地址）也会改变 比如：
cosnt double pi2 = 6.28;

cptr = &pi2; //正确  *cptr为6.28

cout << cptr << endl； //cptr的值变了
```

2. const 指针表示指针本身是一个常量。由于指针是对象，因此就像其他对象一样，允许把指针本身定位常量。const 指针必须初始化，并且一旦初始化，const 指针的值就不能改变了。const 指针的值到底是什么？起始就是指针所指向的地址，这个地址就是一个对象的地址

3. 把`*`放在 const 前面就表示指针是个常量，这样的书写行使意味着不变的是指针本身的值，而不是指向的对象的值(内容)，也就是说，这个地址不能再变了，但是我们可以改变那个地址上存放的内容

```c++
int i = 42;

int * cosnt p = &i； //p是一个const指针

cosnt int i2 = 44;

p = &i2; //错误 不能改变p的值，即地址

//虽然不能给p赋值，也就是不能改变p的值，但是我们可以改变p所指的对象的内容。比如：

*p = 46; //正确 此时i为46
```

```c++
#include <iostream>
template<typename T>
void func(const T ptr) {
    //NOTE: int * const
    int a = 10;

    *ptr = a;
}

int main() {

    int a = 120;
    int *ptr = &a;
    func(ptr);
    std::cout << *ptr << '\n';
    return 0;
}

```

4. 指针本身是一个常量(即 const 指针)并不意味着不能通过指针修改其所指对象的值，能否这样做完全依赖于所指对象的类型

```c++
const double pi = 4.4;

const double *const pip = &pi // pip是一个指向常量对象的const指针
```

pip 是一个指向常量的常量指针，则不论 pip 所指的对象值还是 pip 自己存储的那个地址都不能改变。

---

## 左值，右值，左值引用，右值引用(\*\*)

### 1. 左值和右值

C++任何一个对象要么是左值要么是右值

例如`int i = 10`, `i`和`10`都是对象

左值：拥有地址属性的对象就叫左值，左值来源于 C 语言的说法，能放在"="左边的就是左值

> 左值也可以放在"="右边

右值：不是左值的对象就是右值。或者说无法操作地址的对象就叫做右值。一般来收，判断一个对象是否为右值，就看它是不是左值，有没有地址属性，不是左值，那就是右值

比如临时对象，就都是右值，临时对象的地址属性无法使用

> 注意：左值也可以放在"="右边，但右值绝对不可以放在"="左边

```c++
#include <iostream>

int main() {

  int i = 10;
  int i2 = (i + 1);// i + 1 是一个临时对象
  ++i = 200;//++i 是先给i加1，然后返回i
 // i++ = 200;//先返回一个临时变量，这个临时变量的值等于i的值，而临时变量没有地址属性

  return 0;
}

```

### 2. 引用的分类

1. 普通左值引用：就是一个对象的别名，只能绑定左值，无法绑定常量对象

```c++
#include <iostream>

int main() {

  int i = 10;
  int& re = i;

  std::cout << re << std::endl;
  return 0;
}

```

2. const 左值引用：可以对常量起别名，可以绑定左值和右值
   > C++规定const T&这种方式的左值引用可以接受右值(即亡值、纯右值)

```c++
#include <iostream>

int main() {

  const int i = 10;
  const int& re = (i + 1);

  std::cout << re << std::endl;
  return 0;
}
```

3. 右值引用：只能绑定右值的引用

```c++
#include <iostream>

int main() {

  int i = 10;
  int&& rrefi = 200;
  int&& r1 = i ++;
  std::cout << r1 << std::endl;
  return 0;
}

```

---

## move 函数，临时对象(\*\*)

### 1. move 函数

1. 右值看重对象的值而不考虑其地址属性，move 函数可以对一个左值使用，是操作系统不再在意其地址属性，将其完全视作为一个右值

2. move 函数让操作的对象失去了地址属性，所以我们有义务保证以后不再使用该变量的地址属性，简单来说就是不再使用该变量，因为左值对象的地址是其使用时无法绕过的属性

```c++
#include <iostream>
int main()
{
  int i = 10;
  // FIX: int&& rrefi = i; i是一个左值
  int&& rrefI = std::move(i);
  // NOTE: i依旧是一个左值，move(i)是将i的地址属性忽略掉，是一个右值
  return 0;
}

```

### 2. 临时对象

1. 右值都是不体现地址的对象，那么，还有什么能比临时对象更加没有地址属性呢？右值引用主要负责处理的就是临时对象

2. 程序执行时生成的中间对象就是临时对象，注意所有的临时对象都是右值对象，因为临时对象昌盛后很快就可能被销毁，使用的是它的值属性

```c++
#include <iostream>

int getI()
{
  return 10;// NOTE:该函数返回的值就是临时对象
}


int main()
{
  int i = 10;
  int&& rrefI = getI();
  return 0;
}
```

---

## 万能引用和引用折叠

### 万能引用

- 只用两种引用的形式，左值引用和右值引用，万能引用不是一种引用类型，它存在于模板的引用折叠情况，但能够接受左值和右值
- 一个右值一旦有名字那么就变成了左值
- 区分左值和右值的一个简单方式就是能不能取到地址

```c++
#include <iostream>

void f(int& t) {
    std::cout << "lvalue" << '\n';
}

void f(int&& t) {
    std::cout << "rvalue\n";
}
template<typename T>
void test(T&& v) {
    f(std::forward<T>(v));
}

int main() {
    int i = 0;
    test(i);
    test(1);
    test(std::move(i));

    return 0;
}
```

### 引用折叠

声明引用的引用是非法的，但编译器却可以在模板实例化过程产生引用的引用

`int&&&& j = 1`

模板实例化过程中出现这种情况就会发生引用折叠，如果任一引用为左值引用，则结果为左值引用，若两个皆为右值引用结果为右值引用。

```c++
#include <ios>
#include <iostream>
#include <type_traits>

void f(int& t) {
    std::cout << "lvalue" << '\n';
}

void f(int&& t) {
    std::cout << "rvalue\n";
}
template<typename T>
void test(T&& v) {
    std::cout << "is int& -> " << std::is_same_v<T , int&> << std::endl;
    std::cout << "is int  -> " << std::is_same_v<T , int> << std::endl;
}

int main() {
    std::cout << std::boolalpha;
    int i = 0;
    test(i);
    test(1);

    return 0;
}
```

## 可调用对象(\*\*)

如果一个对象可以使用调用运算符"()",()里面可以放参数，这个对象就是可调用对象。

### 1. 函数

函数可以自然调用()运算符，是最典型的可调用对象

```c++
#include <iostream>

using pf_func = void(*)(int); //函数指针



void test(int i)
{
  std::cout << i << std::endl;
  std::cout << "hello world" << std::endl;
}

void myFunc(pf_func pf , int i)
{
  pf(i);
}

int main()
{
  test(200);
  myFunc(test, 500);
  return 0;
}

```

关于默认实参

- 在函数声明中，所有在拥有默认实参的形参之后的形参必须拥有在这个或同一个作用于中先前的声明中所提供的默认实参
- 简单来说，默认实参只能从右往左声明

```c++
#include <iostream>

void f(int , int , int = 10);
void f(int , int = 6 , int);
void f(int = 4 , int  , int);
void f(int a , int b , int c) {
    std::cout << a << " " << b << ' ' << c << '\n';
}


int main() {
    f();
    return 0;
}

```

### 2. 仿函数

具有 operator()函数的类对象，此时类对象可以当做函数使用，因此称为仿函数

```c++
#include <iostream>

class Test {
public:
  void operator()(int i) {
    std::cout << i << std::endl;
    std::cout << "operator()" << std::endl;
  }
};

int main() {
  Test t;
  t(200);
  return 0;
}

```

### 3. lambda 表达式

就是匿名函数，普通的函数在使用前需要找个地方将这个函数定义，于是 C++提供了 lambda 表达式。需要函数时直接在需要的地方写一个 lambda 表达式，省去了定义函数的过程，增加了开发效率

> lambda 表达式的格式是: 最少是"[]{}"，完整格式是"[]()->ret{}"

#### lambda 表达式各个组件介绍

1. []代表捕获列表: 表示 lambda 表达式可以访问前文的哪些变量

   1. []表示不捕获任何变量
   2. [=]： 表示按值捕获所有变量
   3. [&]：表示按照引用捕获所有变量

   > =、&也可以混合使用

   4. [=,&i]： 表示变量 i 引用传递，除 i 的所有变量用值传递
   5. [& , i]：表示变量 i 用值传递，除 i 的所有变量用引用传递

   > 当然，也可以捕获单独的变量

   6. [i]：表示以值传递的形式捕获
   7. [&i]：表示以引用传递的方式捕获

2. ()代表 lambda 表达式的参数，函数有参数，lambda 自然也有

3. ->ret 表示指定 lambda 的返回值，如果不指定，lambda 表达式也会推断出一个返回值的

4. {}就是函数体了，和普通函数的函数体功能完全相同

```c++
#include <iostream>

int main() {
  int i = 10;
  auto t = [&i](int element)-> int{
    std::cout << i << std::endl;
    std::cout << "hello world" << std::endl;
    std::cout << element << std::endl;
    return element - 1;
  }(100);

  std::cout << t << std::endl;

  return 0;
}

```

```c++
#include <functional> // NOTE: 可以提供函数指针完全相同的效果
#include <iostream>
using pf_type = void (*)(int);
using func_type = std::function<void(int)>;

void test() { std::cout << "This is test()function " << std::endl; }

void myFunc(pf_type pf, int i) { pf(i); }

void newFunc(func_type fun, int i) { fun(i); }

int main() {
  int i = 10;

  myFunc(
      [](int i) { // NOTE:
                  // myFunc参数里面有一个函数指针和一个整型变量，lambda表达式用过函数指针被调用
        std::cout
            << i
            << std::
                   endl; // NOTE:
                         // 当一个lambda表达式作为一个函数指针对象时，它的捕获列表必须为空
        std::cout << "lambda" << std::endl;
      },
      200);

  newFunc(
      [i](int i1) { // NOTE:
                    // 使用<functional>库的函数指针，使得lambda可以捕获变量
        std::cout << i << std::endl;
        std::cout << i1 << std::endl;
      },
      100);

  return 0;
}


```

---

## 智能指针

### 1. 智能指针概述

1. 为什么要有智能指针：直接用`new`和`delete`运算符极其容易导致内存泄露，而且非常难以避免，于是人们发明了智能指针这种可以自动回收内存的的工具

2. 智能指针一共就三种：普通的指针可以单独一个指针占用一块内存，也可以多个指针共享一块内存

   1. 共享型智能指针：`shared_ptr`
      > 同一块堆内存可以被多个`shared_ptr`共享
   2. 独享型智能指针：`unique_ptr`
      > 同一块堆内存只能被一个`unique_ptr`拥有
   3. 弱引用智能指针：`weak_ptr`
      > 也是一种共享型智能指针，可以视为对共享型智能指针的一种补充

```c++
#include <iostream>

int main() {
  int *pi = new int(10);
  int *pi2(pi); //NOTE: pi和pi2共享同一块内存
  return 0;
}
```

3. (\*)智能指针的注意事项

   智能指针和裸指针不要混用

### 2. shared_ptr

#### 1. 工作原理

1. 我们在动态内存分配时，堆上的内存必须通过栈上的内存来寻址，也就是说栈上的指针(堆上的指针也可以指向堆内存，但终究是要通过栈来寻址)是寻找堆内存的唯一方式

2. 所以我们可以给堆内存添加一个引用计数，有几个指针指向它，它的引用计数就是几。当引用计数为 0 时，操作系统就会释放掉这块内存

#### 2. 常用操作

##### 1. 初始化

使用`new`运算符初始化

> 一般来说不推荐使用`new`进行初始化，因为 C++标准提供了专门创建`shared_ptr`的函数`make_shared()`，该函数是经过优化的，效率更高

使用`make_shared()`初始化

`注意` ： 千万不要用裸指针初始化`shared_ptr`，容易出现内存泄露的问题

使用复制构造函数初始化也行

```c++
#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> shared1(new int (100));
  std::shared_ptr<int> shared2 = std::make_shared<int>(100);
  std::shared_ptr<int> shared3(shared2);// 使用复制构造函数初始化也行
  int *pi = new int(100);

  std::shared_ptr<int> shared4(pi);
  // delete pi; // NOTE: 会造成二次释放(堆内存的重复释放)

  return 0;
}

```

##### 2. shared_ptr 的引用计数

智能指针就是通过引用计数来判断释放内存的时机的  
`use_count()`函数可以得到`shared_ptr`对象的引用计数

```c++
#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> shared1 = std::make_shared<int>(100);
  std::cout << shared1.use_count() << std::endl;

  std::shared_ptr<int> shared2(shared1);
  std::cout << shared1.use_count() << std::endl;

  shared2.reset(); // NOTE: 释放掉该指针对对象的控制权
  std::cout << shared1.use_count() << std::endl;

  return 0;
}

```

#### 3. 把 shared_ptr 当成普通指针使用

智能指针可以像普通指针那样使用，`shared_ptr`早已对各种操作进行了重载，就当它是普通指针就可以了

```c++
#include <iostream>
#include <memory>

int main() {


  std::shared_ptr<int> shared1 = std::make_shared<int>(100);
  std::cout << *shared1 << std::endl;

  return 0;
}

```

#### 4. 常用函数

1. `unique`函数
   > 判断该`shared_ptr`对象是否独占，若独占，返回`true`，否则返回`false`

```c++
#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> shared1 = std::make_shared<int>(100);
  std::cout << shared1.unique() << std::endl;

  std::shared_ptr<int> shared2(shared1);
  std::cout << shared1.unique() << std::endl;


  shared2.reset();
  std::cout << shared1.unique() << std::endl;

  return 0;
}

```

2. `reset`函数

   1. 当`reset`函数有参数时，改变此`shared_ptr`对象指向的内存
   2. 当`reset`函数无参数时，将此`shared_ptr`对象置空，也就是将对象内存的指针设置为`nullptr`

```c++
#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> shared1 = std::make_shared<int>(100);
  std::cout << shared1.unique() << std::endl;

  std::shared_ptr<int> shared2 = std::make_shared<int>(100);

  shared1.reset(new int(100));

  shared2 = shared1;
  shared1.reset();
  return 0;
}

```

3. `get`函数， 强烈不推荐使用

如果一定要用，那么一定不能`delete`返回的指针

```c++
#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> shared1 = std::make_shared<int>(100);
  std::cout << shared1.unique() << std::endl;

  delete shared1.get(); // NOTE: 堆内存重复释放

  return 0;
}

```

4. `swap`函数

   > 交换两个智能指针所指向的内存

1. `std`命名空间中全局的`swap`函数
1. `shared_ptr`类提供的`swap`函数

```c++
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> shared1 = std::make_shared<int>(100);
  std::shared_ptr<int> shared2 = std::make_shared<int>(1000);

  shared1.swap(shared2);
  std::cout << *shared1 << std::endl;
  std::cout << *shared2 << std::endl;

  std::swap(shared1, shared2);
  std::cout << *shared1 << std::endl;
  std::cout << *shared2 << std::endl;

  return 0;
}

```

#### 5. 关于智能指针创建数组的问题

#### 6. 用智能指针作为参数传递时直接值传递就行

`shared_ptr`的大小为固定的`8`或`16`字节

> 也就是两倍指针的大小，32 位系统指针为`4`个字节，64 位系统指针为`8`个字节，`shared_ptr`中就两个指针，所以直接按值传递就行了

#### 7. 总结

在现代程序中，当想要共享一块堆内存时，优先使用`shared_ptr`，可以极大的减少内存泄露的问题

### 3. weak_ptr

#### 1. 介绍

1. 这个智能指针是在 C++11 的时候引入标准库，它的出现完全是为了弥补`shared_ptr`的天生缺陷，其实`shared_ptr`可以说是几乎完美
2. 只是通过引用计数实现的方式也引来了引用成环的问题，这种问题靠他自己是没法解决的，所以在 C++11 的时候将`shared_ptr`和`weak_ptr`一起引入了标准库，依次来解决循环引用的问题

#### 2. shared_ptr 循环引用的问题

```c++
#include <iostream>
#include <memory>

class B;

class A {

public:
  std::shared_ptr<B> sharedB;
};

class B {

public:
  std::weak_ptr<A> sharedA; // NOTE: 只有把其中一个堆内存用weak_ptr来控制，这两块堆内存才会被释放
};

int main() {
  // std::shared_ptr<int> shared1 = std::make_shared<int>(100);
  // std::cout << shared1.use_count() << std::endl;
  //
  // std::weak_ptr<int> weak1(shared1);
  // std::cout << shared1.use_count() << std::endl;


  std::shared_ptr<A> sharedA1 = std::make_shared<A>();
  std::shared_ptr<B> sharedB1 = std::make_shared<B>();

  sharedA1->sharedB = sharedB1; // NOTE: 两个堆内存，你指我，我指你，双方都在等着对方释放
  引用计数都为1，当引用计数为0的时候，堆内存才会被释放，所以这就造成了内存泄露
  sharedB1->sharedA = sharedA1;

  return 0;
}
```

#### 3. weak_ptr 的作用原理

`weak_ptr`的作用对象需要绑定到`shared_ptr`对象上，作用原理是`weak_ptr`不会改变`shared_ptr`的引用计数，只要`shared_ptr`对象的引用计数为 0，就会释放内存，`weak_ptr`不会影响到释放内存的功能

#### 4. 总结

`weak_ptr`是用比较少，就是为了处理`shared_ptr`循环引用问题设计的

### (\*)unique_ptr

#### 1. 介绍

独占式智能指针，在是用智能指针时，我们一般优先考虑独占式智能指针，因为消耗更小，如果发现内存需要共享，那么再去是用`shared_ptr`

#### 2. unique_ptr 的初始化

> 和 shared_ptr 完全类似

1. 使用`new`运算符初始化
2. 使用`make_unique`初始化

```c++
#include <iostream>
#include <memory>

int main() {

  std::unique_ptr<int> unique1(new int(100));
  std::unique_ptr<int> unique2 = std::make_unique<int>(1000);
  std::cout << *unique1 << std::endl;
  std::cout << *unique2 << std::endl;

  return 0;
}
```

#### 3. unique_ptr 的常用操作

1. `unique_ptr`禁止复制构造函数，他禁止赋值运算符的重载运算。否则独占毫无意义
2. `unique_ptr`允许移动构造，移动赋值。移动语义代表之前的对象已经失去了意义，移动操作自然不影响独占的特性

```c++
#include <iostream>
#include <memory>

int main() {

  std::unique_ptr<int> unique1 = std::make_unique<int>(100);
  std::unique_ptr<int> unique2 = std::make_unique<int>(1000);

  unique2 = std::move(unique1);
  std::cout << *unique2 << std::endl;

  return 0;
}
```

4. `reset()`函数
   1. 不带参数的情况下，释放智能指针的对象，并将智能指针置空
   2. 带参数的情况下，释放智能指针的对象，并将智能指针指向新的对象

```c++
#include <iostream>
#include <memory>

int main() {

  std::unique_ptr<int> unique1 = std::make_unique<int>(100);
  std::unique_ptr<int> unique2 = std::make_unique<int>(1000);

  unique1.reset();
  unique2.reset(new int(12));

  std::cout << *unique2 << std::endl;

  return 0;
}
```

4. 将`unique_ptr`的对象转化为`shared_ptr`的对象，当`unique_ptr`的对象作为一个右值时，就可以将该对象转化为`shared_ptr`的对象
   > 这个使用的并不多，需要将独占式指针转化为共享式指针常常是因为先前设计失误
   > 注意：shared_ptr 对象无法将其转化为 unique_ptr 对象

```c++
#include <iostream>
#include <memory>

void myfunc(std::unique_ptr<int> unique3) {
  std::shared_ptr<int> shared1(std::move(unique3));
} // NOTES: 一旦将一个对象转化成右值时，必须保证以后不再单独是用这个对象

int main() {

  std::unique_ptr<int> unique1 = std::make_unique<int>(100);
  std::unique_ptr<int> unique2 = std::make_unique<int>(1000);

  return 0;
}
```

### (\*\*)智能指针的适用范围

#### 1. 能使用智能指针就尽量是用智能指针 ， 但是有些情况下不能使用智能指针

有些函数必须使用 C 语言的指针，这些函数又没有替代，这种情况下，才使用普通的指针，其他情况一律是用智能指针

必须使用 C 语言的指针包括:

1. 网络传输函数：比如 windows 下的`send`,`recv`函数，智能使用 C 语言的指针，无法替代
2. C 语言文件操作部分：这方面 C++已经有了替代品，C++的文件部分完全支持智能指针，所以在做大型项目时，推荐使用 C++的文件操作功能

#### 2. 我们应该是用哪个智能指针呢？

1. 优先使用`unique_ptr`，内存需要共享时使用`shared_ptr`
2. 当使用`shared_ptr`时，如果出现循环引用的情况下，再去考虑`weak_ptr`

---

## 模板与泛型编程

### 模板介绍，类模板与模板实现原理

C++的三大模块，面向过程、面向对象、模板与泛型。面向过程就是 C 语言，面向对象就是类，现在轮到模板与泛型了

#### 1. 模板的介绍

1. 模板能够实现一些其他语法难以实现的功能，但是理解起来会更加困难，容易导致新手摸不着头脑
2. 模板分为类模板和函数模板，函数模板又分为普通函数模板和成员函数模板

#### 2. 类模板基础

> 类模板的写法十分固定

#### 3. 模板的实现原理

模板需要编译两次，在第一次编译时仅仅检查最基本的语法，比如括号是否匹配。等函数真正被调用的时候，才会真正生成需要的类或函数

所以这导致了一个结果，就是不论是模板类还是模板函数，声明与实现都必须放在同一个文件中，因为程序在编译期就必须知道函数具体的实现过程，如果实现和声明分文件编写，需要在链接时才可以看到函数的具体实现过程，这当然会报错

于是人们发明了`.hpp`文件来存放模本这种声明与实现在同一文件的情况

```c++
/*
* filename: Myclass-template.hpp
*/


#pragma once

#include <cstddef>
template <typename T> class MyArray {
  using iterator = T *;
  using const_iterator = const T *;

private:
  T *data;

public:
  // NOTE: size_t在32位系统上定义为 unsigned
  // int，也就是32位无符号整型。在64位系统上定义为 unsigned long ,
  // 也就是64位无符号整形。

  MyArray(size_t count);

  iterator begin() const;

  const_iterator cbegin() const;

  ~MyArray();
};

template <typename T> MyArray<T>::MyArray(size_t count) {
  if (count) {
    data = new T[count]();
  } else
    data = nullptr;
}

template <typename T> MyArray<T>::~MyArray() {
  if (data)
    delete[] data;
}

// NOTE: 定义迭代器得使用typename
template <typename T> typename MyArray<T>::iterator MyArray<T>::begin() const {
  return data;
}

template <typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const {
  return data;
}

```

```c++
/*
* filename = main.cpp
*/

#include <iostream>
#include <string>
#include <memory>
#include "Myclass-template.hpp"

int main() {

  MyArray<int> st(100);
  std::cout << *st.begin() << std::endl;
  return 0;
}

```

### (\*) "initializer_list" 和 "typename"

#### initializer_list

1. initializer_list 介绍：initializer_list 其实就是初始化列表，我们可以用初始化列表初始化各种容器，比如`vector` 、`array`

```c++
/*
 * filename: Myclass-template.hpp
 */

#pragma once

#include <cstddef>
#include <initializer_list>
#include <type_traits>
// NOTE:类型萃取
#include <vector>

// NOTE: 模板特化

template <typename T> struct get_type {
  using type = T;
};

template <typename T> struct get_type<T *> {
  using type = T;
};

template <typename T> class MyArray {
private:
  T* data;
  // NOTE: 在创建的时候实际上是创建了两层指针，第一层是data，第二层是data里面的元素
  //析构函数只删除了第一层指针，导致第二层还留着，造成内存泄露
  //得使用智能指针来避免的这个问题
  //如果是容器的话，直接用vector就好了
  //
  using iterator = T *;
  using const_iterator = const T *;
  unsigned int cnt;

public:
  MyArray(std::size_t count);
  MyArray(const std::initializer_list<T> &list);
  MyArray(std::initializer_list<T> &&list);
  iterator begin() const;
  const_iterator cbegin() const;

  T &operator[](unsigned int query) const { return data[query]; }

  ~MyArray();
};

template <typename T> MyArray<T>::MyArray(std::size_t count) : cnt(count) {
  if (data) {
    data = new T[count]();
  } else
    data = nullptr;
}

template <typename T> typename MyArray<T>::iterator MyArray<T>::begin() const {
  return data;
}

template <typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const {
  return data;
}

template <typename T>
MyArray<T>::MyArray(const std::initializer_list<T> &list) {
  if (list.size()) {
    unsigned int count = 0;
    data = new T[list.size()]();
    if (std::is_pointer<T>::value) {

      for (auto elem : list)
        data[count++] = new typename get_type<T>::type(*elem);

    } else {
      for (const auto &elem : list)
        data[count++] = elem;
    }
  } else
    data = nullptr;
}

template <typename T> MyArray<T>::MyArray(std::initializer_list<T> &&list) {
  if (list.size()) {
    unsigned int count = 0;
    data = new T[list.size()]();

    for (auto &elem : list)
      data[count++] = elem;
  } else
    data = nullptr;
}

template <typename T> MyArray<T>::~MyArray() {
  delete[] data;
}
```

```c++
/*
 * filename = main.cpp
 */

#include "Myclass-template.hpp"
#include <initializer_list>
#include <iostream>
#include <vector>

int main() {

  std::initializer_list<int> iList{1, 2, 3, 4, 5, 6};
  std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6};

  int i1 = 10, i2 = 20, i3 = 30, i4 = 40;

  std::initializer_list<int *> iList1{&i1, &i2, &i3, &i4};
  MyArray<int *> arrayP(iList1);
  for (int i = 0; i < iList1.size(); i++)
    std::cout << *arrayP[i] << std::endl;

  return 0;
}
```

#### typename

1. 在定义模板时表示这个一个待定的类型

2. 在类外表明自定义类型时使用

在 C++的早起版本，为了减少关键字的数量，用`class`来表示模板的参数，但是后来因为第二个原因，不得不引入`typename`关键字

### (\*)函数模板，成员函数模板

```c++
#include "Myclass-template.hpp"
#include <iostream>
#include <memory>
#include <vector>

namespace mystd {
// NOTE: 函数模板
template <typename iter_type, typename func_type>
void for_each(iter_type first, iter_type last, func_type func) {
  for (auto iter = first; iter != last; iter++) {
    func(*iter);
  }
}

} // namespace mystd

int main() {
  std::vector<int> ivec{1, 2, 3, 4, 5};
  mystd::for_each(ivec.begin(), ivec.end(), [](int &elem) { ++elem; });

  for (auto &elem : ivec) {
    std::cout << elem << std::endl;
  }

  return 0;
}

```

#### 2. 成员函数模板

```c++
#include <iostream>
#include <memory>
#include <vector>

namespace mystd {
// NOTE: 函数模板
template <typename iter_type, typename func_type>
void for_each(iter_type first, iter_type last, func_type func) {
  for (auto iter = first; iter != last; iter++) {
    func(*iter);
  }
}

template <typename T> class Myvector {
public:
  template <typename T2> void OutPut(const T2 &elem);
};
// NOTE:类外定义函数

template <typename T>
template <typename T2>

void Myvector<T>::OutPut(const T2 &elem) {
  std::cout << elem << std::endl;
}

} // namespace mystd

int main() {
  std::vector<int> ivec{1, 2, 3, 4, 5};
  mystd::for_each(ivec.begin(), ivec.end(), [](int &elem) { ++elem; });

  for (auto &elem : ivec) {
    std::cout << elem << std::endl;
  }
  mystd::Myvector<int> myvec;

  for (const auto &elem : ivec) {
    myvec.OutPut(elem);
  }

  return 0;
}

```

### (\*) 默认模板参数

1. 默认模板参数是一个经常使用的特性，比如在定义`vector`对象时，我们就可以使用默认分配器

2. 模板默认参数和普通函数的默认参数一样，一旦一个参数有了默认参数，它之后的参数都必须有默认参数

3. 函数模板使用默认模板参数

```c++
#include "Myclass-template.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

namespace mystd {
// NOTE: 函数模板

using void_int_func_type = std::function<void(int&)>;

template <typename iter_type, typename func_type = void_int_func_type>
void for_each(iter_type first , iter_type last , func_type func = [](int &elem) {++elem;}) {
  for(auto iter = first; iter != last; iter ++)
    func(*iter);
}



} // namespace mystd

int main() {
  std::vector<int> ivec{1, 2, 3, 4, 5};
  mystd::for_each(ivec.begin(), ivec.end());

  for (auto &elem : ivec) {
    std::cout << elem << std::endl;
  }

  return 0;
}

```

4. 类模板使用默认模板参数

```c++
#include "Myclass-template.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

namespace mystd {

template <typename T, typename allocator_type = std::allocator<T>> class Myvector {
public:
  template <typename T2> void OutPut(const T2 &elem);
};

template <typename T, typename allocator_type>
template <typename T2>
void Myvector<T, allocator_type>::OutPut(const T2 &elem) {
  std::cout << elem << std::endl;
}

} // namespace mystd

int main() {
  mystd::Myvector<int> ivec;
  ivec.OutPut(29);

  return 0;
}

```

### (\*) 模板的重载、全特化和偏特化

#### 1. 模板的重载

函数模板是可以重载的（类模板不能重载），通过重载可以应对更加复杂的情况。比如在处理`char*`和`string`对象时，虽然都可以代表字符串，但`char*`在复制时直接拷贝内存效率明显更高，string 就不得不调用构造函数了，所以在一些比较追求效率的程序中对不同类型进行不同的处理还是非常有意义的

```c++
#include <iostream>
#include <string>
#include <vector>

template <typename T> void test(const T &param) {
  std::cout << "void test(const T &param)" << std::endl;
}

template <typename T> void test(T *param) {
  std::cout << "void test(T *param)" << std::endl;
}

void test(double param) {
  std::cout << "void test(double param)" << std::endl;
}

int main() {
  test(100);
  int i = 100;
  test(&i);
  test(2.2);
  int a = 20 , b = 30;
  return 0;
}
```

其实函数模板的重载和普通函数的重载没有什么区别

在讲完类模板特化就能知道重载和特化的区别了，这一点暂时不用在意了

#### 2. 模板的特化

1. 模板特化的意义

函数模板可以重载以应对更加精细的情况，类模板不能重载，但可以特化来实现类似的功能

2. 模板的特化可以分为两种：全特化和偏特化

   1. 模板的全特化：
      就是指模板的实参列表与相应的模板参数列表一一对应

   2. 模板的偏特化：
      偏特化就是介于普通模板和全特化之间，只存在部分类型明确化，而非将模板唯一化

3. 其实对于函数模板来说，特化与重载可以理解为一个东西

```c++
#include <iostream>
#include <string>
#include <vector>


template<typename T1 , typename T2>
class Test {
public:
  Test() {
    std::cout << "common template" << std::endl;
  }
};

template<typename T1 , typename T2>
class Test<T1* , T2*> {
public:
  Test() {
    std::cout << "point template" << std::endl;
  }
};

// NOTE:部分特化
template<typename T2>
class Test<int, T2> {
public:
  Test() {
    std::cout << "int -semi-special" << std::endl;
  }
};

// NOTE: 全特化
template<>
class Test<int , int> {
public:
  Test() {
    std::cout << "int ,int complete special" << std::endl;
  }
};

int main() {

  Test<int * , int *> test1;
  Test<int , double> test2;
  Test<int , int> test3;
  Test<int* , int> test4;
  return 0;
}

```

##### 总结

函数模板的重载，类模板的特化还是比较重要的知识点，应当掌握，在一些比较复杂的程序中，模板的重载与特化还是经常使用的

---

## STL

---

## IO 库

### IO 库介绍

#### IO

`io`就是`input` 、`output`的简写，也就是输入输出的功能，数据在内存、磁盘、输入输出设备之间移动就是`io`功能
![](https://s3.bmp.ovh/imgs/2023/04/16/c4f1ab410958bb36.png)

#### IO 库组成部分

1. C++定义了`ios`这个基类来定义输入输出的最基本操作，这个类的具体功能我们无需了解，只需了解 C++io 库所有的类都继承自这个类即可
2. `istream` 、`ostream`这两个类直接继承自`ios`类
   1. `ostream`类定义了从内存到输出设备（比如显示器）的功能，我们最常使用的`cout`就是`ostream`类对象
   2. `istream`类定义了从输入设备（比如键盘）到内存的功能，我们最常使用的`cin`就是`istream`类对象
   3. `iostream`文件定义了`ostream`、`istream`类的对象，就是`cout`和`cin`，所以我们只要简单的引入`iostream`这个文件，就可以方便的使用这两个对象

注意：这个输入，输入相对于内存来说，输入到内存，就是`istream`

3. `ifstream` 、`ofstream`类分别继承自`istream`类和`ostream`类
   1. `ifstream`定义了磁盘到内存的功能。因为`istream`重载了`<<`运算符，所以`ifstream`对象也可以用`<<`运算符来将文件数据写入内存，除了`=`的所用重载运算符都是可以被继承的
   2. `ofstream`定义了从内存到磁盘的功能，与`ifstream`同理，也可以用`>>`操作数据流
   3. `fstream`文件引入了`ifstream`与`ofstream`，所以我们只要引入`ifstream`这个头文件，就可以操作文件流功能了

注意：这个输入输出同样是相对内存来说的

内存与输入输出设备的数据流动，磁盘与内存的数据流动已经介绍完了。磁盘输入输出设备无法直接交互，必须通过内存  
`io`库还为我们额外定义了字符串的输入输出类，因为对字符串的操作极为频繁，所以这个库还是很有意义的

4. `istringstream` 、`ostringstream`分别继承自`istream`类和`ostream`类

   1. `istringstream`定义了从指定字符串到特定内存的功能，与`ifstream`同理，也可以用`<<`运算符操作数据
   2. `ostringstream`定义了从特定内存到指定字符串的功能，可以用`>>`运算符操作数据
   3. `sstream`头文件就引入了`istringstream`和`ostringstream`，所以我们只要引入`sstream`这个头文件，就可以使用字符串与内存直接交互数据的功能

所以我们使用`io`库主要就三个头文件`istream`、`ostream`、`sstream`

```c++
#include <iostream>
// NOTE: 想要输入输出设备与内存交互，就使用iostream
#include <fstream>
// NOTE: 想要与磁盘交互，就使用fstream
int main() {

  return 0;
}

```

### (\*)IO库的注意事项

1. io对象无法使用拷贝构造函数和赋值运算符

```c++
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::istream myCin(std::cin); //BUG: 无法使用拷贝构造

    return 0;
}
```

所以我们使用流对象无法使用值传递，一般使用引用进行传递。

2. io对象的状态

   1. io操作是非常容易出现错误的操作，一些错误是可以修复的，另一部分则发生在系统更深处，已经超出了应用程序可以修正的范围

      - 比如我们使用`cin`向一个`int`类型的数中输入一个字符串，会使`cin`这个对象出现错误

      ```c++

      ```

      - 所以我们在使用io对象是都应该判断io对象状态。

      例如：`while(cin >> val)`或`if(cin >> val)`

      > 不要只用这两个进行控制，最好搭配`iostate`来使用

      ```c++

      #include <ios>
      #include <iostream>
      #include <limits>
      #include <stdexcept>

      int main() {
          int i = 10;
          while(std::cin >> i , !std::cin.eof()) {
              if(std::cin.bad()) { //NOTE: 系统级错误
                  throw std::runtime_error("cin is corrupted\n");
              }

              if(std::cin.fail()) { //NOTE: 格式不对
                  std::cin.clear();//NOTE: 先清空状态栏
                  std::cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');//NOTE:再忽略缓存区
                  std::cout << "data format error, please try again" << std::endl;
                  continue;
              }

              std::cout << i << std::endl;
          }

          std::cout << "process completed" << std::endl;
          return 0;
      }
      ```

   2. 我们需要知道流对象错误的原因，因为不同的错误需要不同的处理方法。

      - io库定义了`iostate`类型，可以完整的表示io对象当前的状态。在不同的平台中，`iostate`实现方法略有区别，在vs中直接用int来代表`iostate`类型，将不同的位置1以表示不同的状态。可以与位操作符一起使用来一次检测或设置多个标志位。
      - 可以用`rdstate`函数来获得io对象当前用iostate类型表示的状态：

      ```c++

      ```

   3. iostate类型有以下状态

      1. badbit状态，系统级错误，一旦表示badbit的位置被置为1，流对象就再也无法使用了。
      2. failbit状态，代表可恢复错误，比如想读取一个数字却读取了一个字符，这种错误就是可以恢复的。当badbit位被置为1时，failbit也会被置1.
      3. eofbit状态，当到达文件结束位置时，eofbit和failbit位都会被置为1
      4. goodbit状态，表示流对象没有任何错误。

   - 只要badbit、falbit、eofbit有一位置被置为1，则检测流状态的条件就会失败。

   4. 标准库还定义了一组成员函数来查询这些标志位的状态。

      1. good()函数在所有错误均为置1的情况下返回`true`
      2. bad() , fail() , eof()函数在对应位置被置1的情况下返回`true`。因为badbit位被置1或eofbit位被置1时，failbit位也会被置1。所以用fail()函数可以准确判断出流对象是否出现错误。
      3. 实际上，我们将流对象当作条件使用的代码就等价于`!fail()`

   5. 流对象的管理

      1. `rdstate`函数，返回一个`iostate`值，对应当前流状态
      2. `setstate(flag)`函数，将流对象设置为想要的状态
      3. `clear`函数，是一个重载函数。
         - clear()，将所有位置0，也就是`goodbit`状态
         - clear(flag)，将对应的条件状态标志位复位
      4. `ignore`函数：
         - 作用：提取输入字符并丢弃他们
         - 函数原型：`istream& ignore(streamsize n = 1 , int delim = EOF)`
           > 读取前n个字符或在读这n个字符进程中遇到delim字符就停止，把读取的这些东西丢掉

### 内存与输入输出设备的交互

1. getline

`getline`其实并不复杂，不过是按行接受数据罢了，因为存储在`string`对象中，所以不容易出现格式错误，但仍然可能出现系统错误，所以在企业级程序中，还是应当对`bad`的情况进行处理

### 内存与磁盘的交互

1. `fstream`相对于`iostream`，对了很多独有的操作

   1. io库默认没有给ifstream和ofstream类提供对象，需要我们自己去定义
   2. fstream对象创建方式有三种

      - 可以使用默认构造函数进行定义，例如：ifstream fstrm

      ```c++

      #include <iostream>
      #include <string>
      #include <fstream>

      int main() {
          std::fstream fs;
          std::ifstream ifs;
          std::ofstream ofs;
          return 0;
      }
      ```

      - 也可以在创建流对象时打开想要的文件，例如`ifstream fstrm(s)`，s可以是字符串，也可以是c风格的字符串指针。文件的mode依赖于流对象的类型

      ```c++
      std::fstream fs("data.txt", std::ios::in | std::ios::out);
      std::ifstream ifs("data.txt");
      std::ofstream ofs("data.txt");
      ```

      - 也可以在打开文件时就制定文件的mode，例如`ifstream fstrm(s , mode)`

   3. fstrm.open(s)函数，打开名为s的文件，并将文件与`fstrm`绑定，s可以是一个是string,也可以是一个c风格的字符串指针

   ```c++

   std::fstream fs;
   fs.open("data.txt");
   ```

   4. fstrm.close()函数，关闭文件。

      > 注意一定不要忘了

   5. fstrm.is_open()函数，返回一个`bool`值，指出与`fstrm`关联的文件是否成功打开且尚未关闭

   模板

   > 让客户输入文件名称，如果文件不存在，就让客户重新输入文件名称，如果文件存在，就将文件全部输出

   ```c++
   #include <iostream>
   #include <limits>
   #include <stdexcept>
   #include <string>
   #include <fstream>

   int main() {
       std::string fileName;
       std::string fileContent;

       while ( std::cin >> fileName, !std::cin.eof() ) {
           if ( std::cin.bad() ) {
               throw std::runtime_error( "cin is corrupeted\n" );
           }

           std::ifstream ifs( fileName );
           if ( ifs.is_open() ) {
               while ( std::getline( ifs, fileContent ) ) {
                   std::cout << fileContent << std::endl;
               }

               if ( ifs.bad() ) {
                   throw std::runtime_error( "ifs is corrupted\n" );
               }

               ifs.close();
           } else {
               ifs.clear();
               ifs.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
               std::cout << "file not exist , please try again\n";
               continue;
           }
       }

       std::cout << "process complete\n";
       return 0;
   }

   ```

2. 文件模式

- 从头写入

```c++
#include <iostream>
#include <fstream>

int main() {
    std::ofstream ofs("data.txt" );

    if(ofs.is_open()) {

        ofs << "hello world\n";

        ofs.close();
    }
    return 0;
}
```

- 从尾写入

```c++
#include <iostream>
#include <fstream>

int main() {
    std::ofstream ofs("data.txt" , std::ios::app);

    if(ofs.is_open()) {

        ofs << "hello world\n";

        ofs.close();
    }
    return 0;
}

```

### 字符串流(sstream)

1. 介绍

`string`流可以向`string`对象写入数据，也可以从`string`对象读取数据，与文件操作类似，只不过数据交互变成了从内存到内存。

2. string流有哪些

   - `istringstream`从string对象读取数据
   - `ostringstream`向string对象写入数据
   - `stringstream`既可以从string对象读取数据，也可以向string对象写数据

3. `string`流对象继承自`iostream`对象，除了继承得来的操作，`string`流对象还有自己的成员来管理流相关的`string`

   1. 对于`string`流，io库是没有向`cout、cin`这样的自定流对象的。流对象需要我们自己去定义。
      - sstream stm: sstream代表一个string流对象的类型，以下同理。stm是一个未绑定的`stringstream`对象。
      - sstream strm(s)：是绑定了一个s的拷贝的`string`流对象，s是一个string对象。
   2. stm.str()：返回`stm`所保存的string的拷贝
   3. stm.str(s)：将s拷贝的stm中，返回void

4. string流对象的作用

   1. 对数据类型进行转化，也就是string和其他类型的转化，这是string流对象最重要的功能。

   - string转int等类型

   ```c++
   #include <iostream>
   #include <limits>
   #include <sstream>
   #include <stdexcept>
   #include <string>
   
   int main() {
   
       std::string str( "nb" );
       std::stringstream ssin( str );
   
       int i = 0;
   
       ssin >> i;
       if ( ssin.bad() ) {
           throw std::runtime_error( "cin is corrupted\n" );
       } else if ( ssin.fail() ) {
           ssin.clear();
           ssin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
           std::cout << "bad string format\n";
       } else {
           std::cout << i << '\n';
       }
       return 0;
   }
   
   ```

   - int等类型转string

   ```c++
   #include <iostream>
   #include <limits>
   #include <sstream>
   #include <stdexcept>
   #include <string>
   
   int main() {
       int strcI = 100;
       std::stringstream ssin;
       std::string str;
       ssin << strcI << std::endl;
       if ( ssin.bad() ) {
           throw std::runtime_error( "ssin is corrupted\n" );
       } else {
           std::cout << ssin.str();
       }
   
       return 0;
   }
   ```

   2. 用于对空格分隔的字符串切分

   ```c++
   #include <iostream>
   #include <limits>
   #include <sstream>
   #include <stdexcept>
   #include <string>
   
   int main() {
       std::string src( "hello world ni hao" );
       std::string dest;
       std::stringstream ssin( src );
   
       while ( ssin >> dest ) {
           std::cout << dest << '\n';
       }
       if ( ssin.bad() ) {
           throw std::runtime_error( "cin is corrupted\n" );
       }
   
       return 0;
   }
   ```

---

# 多线程

## 多线程的概念

### 多线程的重要性

1. 对于一个专业的 C++开发来说，多线程是必须掌握的模块

2. 对于一个计算机来说，是不是说核越多越好呢？不是，多核会导致单核的工作性能下降。当核数多到一定程度后，反而总体运行效率下降了。

### 并发与并行的介绍

一句话来说：并行是同时在不同的处理器上处理不同的任务，并发是“同时”在一个处理器上处理多个任务

解释一下：

1. 并行是指有多个处理器。每个处理器各执行一个线程，互不抢占 cpu 资源，如果线程数量多于 cpu，也没有办法，只能将处理器的时间划分为多个时间段，再将时间段分配给各个线程

2. 并发是指只有一个处理器，但多个线程被轮换快速执行，使得宏观上有了同时执行的效果。作用原理是将单处理器的时间划分为多个时间段，再分配给不同的线程。同一时间段内只能有一个线程在运行，其它线程均处于挂起状态

### 进程的概念

进程的概念在面向进程设计的操作系统(就是 unix，也包括后面衍生出的 linux，mac)和面向线程设计的的操作系统(windows)上有很大区别，两种设计方式的共同点与不同点还是需要理解的。

1. 进程是计算机中的程序对某些数据集合的一次运行活动，是系统进行资源分配和调度的最基本单位，是操作系统的结构基础。再用大白话说一遍，一个可执行程序执行起来，就是一个进程。当然，一个程序要执行起来需要各种资源，这些资源就是数据集合。

2. 在面向进程设计的计算机结构中，进程是程序的基本执行单位，进程包括程序执行的所有资源，同时自己也可以执行。

3. 在面向线程设计的计算机结构中，线程才是程序的基本执行单位，进程不过是线程的容器罢了。进程就像一个仓库，里面存放了程序的所有资源，进程中的线程才是真正执行程序的单元。

### 线程的概念

1. linux 的线程和 windows 的线程还是有很大区别的。

2. linux 的线程就是一种轻量级的进程，只有依靠进程才可以存在。也模拟出了 windows 线程方式，让线程成为真正的执行单元

3. windows 的线程就简单多了，真正执行程序的最小单元

### 总结

说了这么多：其实对进程，线程只是个介绍，这里面水很深。而且 windows 多线程和 linux 多线程的区别并不影响我们学习 C++11 的多线程，C++标准任何平台通用。

现代 C++程序，C++11 的多线程功能才是主流，C++11 的多线程就是 windows 模式的，进程为一个仓库，线程才是程序执行的最小单元。linux 同样完美支持了这些功能。

## (\*)线程的创建

1. 主线程介绍：一个程序执行起来就是一个进程。而 main 函数就是主线程，一旦主线程执行完毕，主线程结束，整个进程就会结束。

2. 子线程介绍：一个线程执行时，我们可以创建出另外一个线程。两个线程各自执行，互不干涉。注意，当主线程执行完毕时，就会强制结束所有子线程，然后进程结束。从这个角度来说，可以认为自线程是主线程的辅助线程。 **但是要明白主线程和子线程是平级的，只不过主线程执行完毕后会给所有子线程发送一个信号，使所有子线程强制结束**

3. 自线程的创建方式：很简单，直接使用`thread`就可以了。

```c++
#include <iostream>
#include <string>
#include <thread>

int main() {

  std::thread my_thread([]() {
      std::cout << "This is a thread" << std::endl;

      });

  return 0;
}
```

4. 子线程创建后如果就不管了，那么会出现非常严重的问题

   1. 有些子线程负责对部分对部分数据的处理，主线程必须要等到子线程处理完毕才能继续执行，所以`join`函数诞生了

   ```c++
    #include <iostream>
    #include <string>
    #include <thread>
   
    int main() {
   
      std::thread my_thread([]() {
          std::cout << "This is a thread" << std::endl;
   
          });
   
      my_thread.join();
      return 0;
    }
   
   ```

   使用`join`函数后，主线程就会处于挂起状态，直到子线程执行完毕才可以继续执行。

   2. 有些子线程和主线程完全分离，各自执行各自的。但主线程执行完毕，子线程就会立马被强制结束，容易导致各种 bug，查都不知道从那里开始查。于是`detach`函数就诞生了。

   ```c++
    #include <iostream>
    #include <string>
    #include <thread>
   
    int main() {
   
      std::thread my_thread([]() {
        for(int i = 0; i < 100000; ++i) {}
          });
   
      my_thread.detach();
      return 0;
    }
   
   ```

   `detach()`函数可以让子线程被 C++运行库接管，就算主线程执行完毕，子线程也会由 C++运行库及时清理相关资源。保证不会出现各种意想不到的 bug

### (\*)传递线程参数

1. 传递子线程函数的参数：直接传递即可。
   > 传递参数分为三种方式：值传递，引用传递，指针传递。

```c++
#include <iostream>
#include <string>
#include <thread>

void test(int t , const int &refi , const int *pi) {

}

int main() {
  int i = 100;
  std::thread my_thread(test , i , i , &i);

  return 0;
}
```

#### 传递参数注意事项

1. 在使用`detach`时不要传递指针，或者说在设置子线程函数时，不要设置指针参数。因为值传递和引用传递并未直接传递地址，而指针却直接传递地址。所以当使用`detach`时，传指针就会导致错误，指针在已经被系统回收，所以千万不要传指针。

```c++
 #include <iostream>
 #include <string>
 #include <thread>

 void test(int i , const int &refi , const int *pi) {
   for(unsigned i = 0; i < 100000; ++i) {
     int i2 = *pi;
   }
 }

 int main() {
   int i = 100;
   std::thread my_thread(test , i , i , &i);
   my_thread.detach();

   return 0;
 }

```

2. 在使用`detach`时不要使用隐式类型转换，`因为很有可能子线程参数还没来得及将参数转换为自己的类型，主线程就执行完毕了。`

```c++
 #include <iostream>
 #include <string>
 #include <thread>

 class Test {
   public:
     Test(int i) {
       std::cout << std::this_thread::get_id() << std::endl;
     }
 };


 void test(const Test &t) {
   std::cout << "child thread id is " << std::this_thread::get_id() << std::endl;
 }

 int main() {

   std::cout << "main thread id is " << std::this_thread::get_id() << std::endl;
   int i = 100;
   std::thread my_thread(test , i);
   my_thread.detach();
   return 0;
 }

```

#### 总结

1. 普通类型在传递子线程函数参数时，直接值传递即可。
2. 类类型传递引用就可以了，类类型传递引用首先会先调用一次复制构造函数生成一个临时变量，故而导致`地址不同`。如果采用值传递，需要两次复制构造函数，开销更大。

```c++
 #include <iostream>
 #include <string>
 #include <thread>

 class Test {
   public:
     Test(int i) {
       std::cout << std::this_thread::get_id() << std::endl;
     }
     Test(const Test &test) {
       std::cout << "Test(const Test &test)" << std::endl;
     }
 };

 void test(const Test &t) {
   std::cout << "child thread id is " << std::this_thread::get_id() << std::endl;
 }

 int main() {
   std::cout << "main thread id is " << std::this_thread::get_id() << std::endl;
   Test t(100);
   std::thread my_thread(test , t);
   my_thread.join();
   return 0;
 }

```

#### std::ref 的用法

根据刚才的演示，使用普通的引用传递会调用依次复制构造函数，导致函数无法对引用对象进行修改，于是 std::ref 诞生了，它可以使子线程在传递参数时不再调用复制构造函数。

```c++
#include <iostream>
#include <string>
#include <thread>

class Test {
  public:
    int i;
    Test(int i) {
      std::cout << std::this_thread::get_id() << std::endl;
    }
    Test(const Test &test) {
      std::cout << "Test(const Test &test)" << std::endl;
    }
};

void test(Test &t) {
  std::cout << "child thread id is " << std::this_thread::get_id() << std::endl;
  t.i = 200;
}

int main() {
  std::cout << "main thread id is " << std::this_thread::get_id() << std::endl;
  Test t(100);
  std::thread my_thread(test , std::ref(t)); // NOTES: 这是真正的传引用，直接传地址
  my_thread.join();

  std::cout << t.i << std::endl;

  return 0;
}
```

### (\*)线程 id 的概念

#### 线程 id 的定义

每个线程都有自己的 id，不管是主线程还是子线程都有自己的 id。直接使用`std::this_thread::get_id()`就可以获得当前线程的 id。

#### 注意

线程是依附于进程存在的，所以不用的进程可以有相同的线程 id。

## (\*)数据共享与保护

多个线程的执行顺序是乱的，具体执行方法和处理器的调度机制有关系。从开发者的角度讲，就是没有规律的

```c++

#include <iostream>
#include <thread>

unsigned g_num = 0;

void test() {
  ++g_num;
}

int main() {

  std::thread my_thread(test);
  my_thread.detach();

  ++g_num;
  return 0;
}

```

### 扩展一下关于汇编的知识

一个进程运行时，数据储存在内存中。如果一个数据要进行运算，必须先将数据拷贝到寄存器中。比如要对栈上的一个`int i`进行`++`操作，需要将`i`拷贝到寄存器当中，将改值自加后再拷贝到原来的内存中。

如果此时有两个线程均进行的是这样的操作，可能出现两个进程都拷贝了`i`原来的值到寄存器，然后各种加一，在拷贝到`i`对应内存的情况，最终导致`i`这个变量只加了一次。

这是同时写数据的情况，那么一读一写呢？这也是有问题的，谁知道读数据时写数据步骤已经到了哪里，谁知道读出来的是个什么东西。

### 数据保护问题

数据保护问题总共有三种情况

1. 至少两个线程对共享数据均进行读操作，完全不会出现数据安全问题。
2. 至少两个线程对共享数据均进行写操作，会出现数据安全问题，需要数据保护。
3. 至少两个线程对共享数据有的进行读操作，有的进行写操作，也会出现数据安全问题，需要进行数据保护。

```c++

```

数据保护的方法一共就两种：互斥锁、原子操作

### 互斥锁

1. 互斥锁的作用原理很简单，对共享数据加锁，当一个线程对这块数据进行操作时，别的线程就无法对该区域数据进行操作

```c++
#include <iostream>
#include <thread>
#include <mutex>

unsigned g_num = 0;
std::mutex my_mutex;

void test() {
  for(unsigned i = 0; i < 100000; ++i) {
    my_mutex.lock(); // NOTE: 锁的区域要尽可能小
    ++g_num;
    my_mutex.unlock();
  }
}

int main() {
  std::thread my_thread(test);

  my_mutex.lock();
  for(unsigned i = 0; i < 100000; ++i) {
    ++g_num;
  }
  my_mutex.unlock();
  my_thread.join();
  std::cout << g_num << std::endl;

  return 0;
}

```

2. 这种方式的互斥锁有个弊端，就是`lock()`之后容易忘记`unlock()`，就和指针类似。于是和智能指针类似，也有了`lock_guard()`，用来防止开发人员忘了解锁。

```c++
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num = 0;
std::mutex my_mutex;

void test() {

  for (unsigned i = 0; i < 100000; ++i) {
    std::lock_guard<std::mutex> lg(my_mutex);
    ++g_num;
  }

  // if(.....) // NOTE: 假设进入判断语句，不一定会解锁
  //
  //  thow....
  //
}

int main() {
  std::thread my_thread1(test);
  std::thread my_thread2(test);

  my_thread1.join();
  my_thread2.join();
  std::cout << g_num << std::endl;

  return 0;
}
```

### 原子操作

> 使用频率远远不及互斥锁

1. 原子操作的原理：

   将一个数据设置为原子状态，使得该数据处于无法被分割的状态，意思就是处理器在处理被设置为原子状态的数据时，其它处理器无法处理该段数据，该处理器也会保证在处理完数据之前不会处理其他数据。

```c++
#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

std::atomic<unsigned> g_num = 0; // 原子对象
// std::mutex my_mutex;

void test() {

  // std::lock_guard<std::mutex> lg(my_mutex);
  for (unsigned i = 0; i < 100000; ++i) {
    ++g_num;
  }

  // if(.....) // NOTE: 假设进入判断语句，不一定会解锁
  //
  //  thow....
  //
}

int main() {
  std::thread my_thread1(test);
  std::thread my_thread2(test);

  my_thread1.join();
  my_thread2.join();
  std::cout << g_num << std::endl;

  return 0;
}
```

#### 总结

在编写多线程代码时，数据保护是一个必须考虑、非常常用的功能。互斥锁的使用频率远远高于原子操作，原子操作看似简单，但当需要保护的数据很多时，就会极其复杂。

所以对于单个数据，可以使用原子操作，其它的使用互斥锁就可以了。

### (\*)死锁

死锁就像两个人在互相等对方。A 说，等 B 来了就去 B 现在所在的地方；B 说，等 A 来了我就去 A 所在的地方，结果就是 A 和 B 都在等对面过来才能去对面。这就导致了一个死循环，放在多线程中，就是死锁。

```c++
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num = 0;
std::mutex my_mutex1;
std::mutex my_mutex2;

void test() {
  for (unsigned i = 0; i < 100000; ++i) {
    std::lock_guard<std::mutex> lg(my_mutex1);
    /*
     *
     *
     *
     */
    std::lock_guard<std::mutex> lg2(my_mutex2);
    ++g_num;
  }
}

int main() {
  std::thread my_thread1(test);

  for (unsigned i = 0; i < 100000; ++i) {
    std::lock_guard<std::mutex> lg2(my_mutex2);
    /*
     *
     *
     *
     */
    std::lock_guard<std::mutex> lg(my_mutex1);
    ++g_num;
  }
  my_thread1.join();
  std::cout << g_num << std::endl;

  return 0;
}
```

解决方法也很简单，只要让两个锁的顺序一致就行。

```c++
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num = 0;
std::mutex my_mutex1;
std::mutex my_mutex2;

void test() {
  for (unsigned i = 0; i < 100000; ++i) {
    std::lock_guard<std::mutex> lg(my_mutex1);
    /*
     *
     *
     *
     */
    std::lock_guard<std::mutex> lg2(my_mutex2);
    ++g_num;
  }
}

int main() {
  std::thread my_thread1(test);

  for (unsigned i = 0; i < 100000; ++i) {
    std::lock_guard<std::mutex> lg(my_mutex1);
    /*
     *
     *
     *
     */
    std::lock_guard<std::mutex> lg2(my_mutex2);
    ++g_num;
  }
  my_thread1.join();
  std::cout << g_num << std::endl;

  return 0;
}

```

但是让两个锁的顺序一致常常是说起来容易做起来难，于是 C++11 提供了`std::lock`。这个模板可以保证多个互斥锁绝对不会出现死锁问题。同时提供了`std::adopt_lock()`的功能来避免忘记释放锁的问题

```c++
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num = 0;
std::mutex my_mutex1;
std::mutex my_mutex2;

void test() {
  for (unsigned i = 0; i < 100000; ++i) {
    std::lock(my_mutex1 , my_mutex2);
    std::lock_guard<std::mutex> lg(my_mutex1 , std::adopt_lock); // NOTE: 放弃加锁功能
    /*
     *
     *
     *
     */
    std::lock_guard<std::mutex> lg2(my_mutex2 , std::adopt_lock);
    ++g_num;
  }
}

int main() {
  std::thread my_thread1(test);

  for (unsigned i = 0; i < 100000; ++i) {
    std::lock_guard<std::mutex> lg2(my_mutex2 );
    /*
     *
     *
     *
     */
    std::lock_guard<std::mutex> lg(my_mutex1);
    ++g_num;
  }
  my_thread1.join();
  std::cout << g_num << std::endl;

  return 0;
}

```
---

# 异常处理


---

# 稀碎的小知识点

## memset

memset(数组名字，值，数组长度);

- memset 的值只能是 0 或者-1
- 数组长度用 sizeof()来求
