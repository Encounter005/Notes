# header and namespace

<!--toc:start-->
- [header and namespace](#header-and-namespace)
  - [一些预处理指令](#一些预处理指令)
    - [1. 防止头文件被包含多次](#1-防止头文件被包含多次)
    - [2. o2/o3 优化](#2-o2o3-优化)
  - [关于 C++头文件](#关于-c头文件)
    - [什么是头文件(.h)](#什么是头文件h)
    - [头文件的价值](#头文件的价值)
    - [头文件的分类](#头文件的分类)
    - [编译过程中的头文件](#编译过程中的头文件)
        - [Example](#example)
    - [头文件中应该写什么](#头文件中应该写什么)
  - [关于 ifndef/define/endif](#关于-ifndefdefineendif)
    - [作用](#作用)
    - [缺失 ifndef 的风险](#缺失-ifndef-的风险)
    - [解决方法](#解决方法)
  - [命名空间](#命名空间)
<!--toc:end-->


## 一些预处理指令

### 1. 防止头文件被包含多次

目的： 保证头文件只被编译一次

```c++
#program once
```

```
/*file: test.h*/
#ifndef _TEST_H_
## static
#define _TEST_H_
#endif
```

### 2. o2/o3 优化

目的：优化 STL，提高 STL 的效率

```c++
#pragma GCC optmize(2 / 3)
```

[优化原理](https://www.zhihu.com/question/27090458)

---

## 关于 C++头文件

### 什么是头文件(.h)

头文件是扩展名为.h 的文件,与源文件(.cpp)一样，头文件也是 C++的源代码，头文件包含了 C++中函数、类、对象等的声明和宏定义，它可以被多个源文件通过#include 引用共享

### 头文件的价值

- C++中有“单一定义原则”，即一个对象只能被定义一次，如果在源文件中定义了一个函数，其他的源文件想要使用这个函数就需要在使用前声明一下这个函数，在编译结束后，编译器链接的时候再去查找这些函数的定义。
- 当只有一两个函数，源文件的数目也不多的时候，我们完全可以直接在源文件中声明这些函数或者变量。但是当我们面临一个大项目是，几百个函数，非常多的变量，100 个以上的源文件。如果每个函数都在每个源文件声明会非常折磨人
- 所以为了达到在不同的源文件中声明的一致性，为了省去这些繁琐又重复的过程，我们可以把这些对象的声明放在少数几个文件中，需要用到这些声明的时候再到这些文件中去查找，这样的文件，就是头文件

### 头文件的分类

对于来源的不同，有两种类型的头文件

1. 程序员编写的头文件
2. 标准库(编译器或者其他库的头文件)

- 对于程序员自己编写的头文件的包含使用"filename";
  `#include"CA.h"`
- 对于标准库头文件的使用<filename>
  `#include<iostream>`

### 编译过程中的头文件

C++代码的编译过程主要通过一下几个过程

- 预编译$\rightarrow$编译$\rightarrow$链接,最后生成可执行文件

==切记==，头文件是不参与编译的，编译器只对源文件进行编译。编译器首先对源文件进行预处理，这一步叫**预编译**。预编译的时候完成头文件中的宏处理，并且根据`#include`指令将头文件展开;

##### Example

下面是一个头文件`CA.h`

```c++

#ifndef CA_H
#define CA_H

int Fun();
#endif

```

有两个源文件 A.cpp 与 B.cpp 都包含了`CA.h`

A.cpp;

```c++
#include "CA.h"

int Fun()
{
 return 1;
}

```

B.cpp

```c++

#include "CA.h"

int Fun1()
{
 return Fun() + 1;
}

```

经过预编译后，这两个源文件分别变为

A.cpp

```c++

#ifndef CA_H
#define CA_H

int Fun();
#endif
int Fun()
{
    return 1;
}

```

B.cpp

```c++

#ifndef CA_H
#define CA_H

int Fun();
#endif
int Fun1()
{
    return Fun() + 1;
}

```

这样就实现了在`A.cpp`与`B.cpp`中对函数 Fun()的声明

---

### 头文件中应该写什么

1. 可以写 const 对象的定义

- 因为全局的 const 对象默认只在当前文件中有效，把 const 对象写进头文件中，即使它被包含到其他多个.cpp 文件中，这个对象也都只在包含它的文件中有效，
  对其他文件来说是不可见的，所以便不会导致多重定义。
- 同理，static 对象的定义也可以放进头文件。

2. 可以写内联函数(inline)的定义

- inline 函数是需要编译器在遇到它的地方根据它的定义把它内联展开的，而并非是普通函数那样可以先声明再链接的，
  内联函数并不会参与链接，所以编译器就需要在编译时看到内联函数的完整定义才行。C++规定，内联函数可以在程序中定义多次，
  只要内联函数的定义在一个.cpp 文件中只出现一次，并且在所有的.cpp 文件中，这个内联函数的定义是一样的，就能通过编译。那么把内联函数的定义放进一个头文件中就能满足以上的要求

3. 可以写类(class)的定义

- 在程序中创建一个类的对象时，编译器只有在这个类的定义完全可见的情况下，才能知道这个类的对象应该如何布局,
  所以，关于类的定义和要求，跟内联函数是基本一样的。所以把类的定义放进头文件，在使用到这个类的.cpp 文件中去包含这个头文件，是一个很好的做法。
  类的定义中包含着数据成员和成员函数，数据成员是要等到具体的对象被创建时才会被定义，被分配空间，但函数成员却是需要在一开始就被定义的。

- 我们可以直接把函数成员的实现代码也写进类定义中。在 C++中，如果函数成员在类的定义体中被定义，那么编译器就会视这个函数为内联的。因此是合法的。

- 注意下，如果把函数成员的定义写来类定义的头文件中，而没有写进类定义范围内，这是非法的，
  因为这个函数成员此时就不是内联的，如果盖头文件被两个级以上的.cpp 文件同时包含，这个函数成员就被重定义了。

## 关于 ifndef/define/endif

### 作用

- 防止头文件被重复包含和编译。
- 头文件重复包含会增大程序大小，重复编译增加编译时间

解释： `#ifndef`起到的效果是防止一个源文件多次包含同一个头文件。那么一个源文件为什么会两次包含同一个头文件呢？

- 你写的`test.cpp`里包含了`a.h`和`b.h`，`a.h`里包含了`b.h`，所以`b.h`就会被包含和编译两次

```c++
/*file: test.cpp*/
#include<a.h>
#include<b.h>
........

/*file: a.h*/
#include<b.h>
........
```

### 缺失 ifndef 的风险

1. 重复定义:
   如果`b.h`中定义了一个变量`b`，在编译`test.cpp`是就会报重复定义的错误

```c++
/*file: test.cpp*/
#include<a.h>
#include<b.h>
........

/*file: a.h*/
#include<b.h>
........

/*file: b.h*/
int b;

```

预处理阶段 test.cpp 展开头文件后会变成:

```c++
/*file: test.cpp*/
/*#include <a.h> -> #include <b.h>*/
int b;
······
/*#include <b.h>*/
int b;
······
```

变量`b`重复定义

2. 无线循环编译

你写的`test.cpp`里包含了`a.h`和`b.h`，`a.h`里包含了`b.h`,`b.h`包含了`a.h`,所以`a.h`、`b.h`就会徐怒汉包含，预处理阶段就会不停地循环展开头文件

```c++
/*file: test.cpp*/
#include <a.h>
#include <b.h>
······
/*file: a.h*/
#include <b.h>
······
/*file: b.h*/
#include <a.h>
······
```

编译器就会报`Error #include nested too deeply`的错误

### 解决方法

以无线循环编译中的情况为例，把`a.h`改写成:

```c++
#ifndef _A_H_
#define _A_H_
...

#include<b.h>
....
#endif
......
```

这样为什么就不报错了呢？

- 在预处理阶段，会先展开`test.cpp`中的头文件`a.h`，执行到`#ifndef _A_H_`,发现此时并没有`_A_H_`
  并没有被 define，所以继续执行`#define_A_H_`,此时`_A_H_`就被 define 了；当展开`b.h`，执行到文件里的`#include<a.h>`,进入`a.h`执行`#ifndef _A_H_`,发现`_A_H_`已经被 define 了，所以直接跳到`a.h`里`endif`之后的语句执行了。
  这样子就可以保证`a.h`不会被重复包含。

如果要确保`b.h`不会被重复包含就该写成:

```c++
#ifndef _B_H_
#define _B_H_
...
#include <a.h>
...
#endif
······
```

4. 建议

- 所有头文件前后到加上 ifndef/define/endif

5. Reference
   1. 主要目的
      - `#ifndef`起到的效果是防止一个源文件两次包含同一个头文件，而不是防止两个源文件包含同一个头文件
   2. 隐藏危险
      - [重复定义](https://www.jb51.net/article/100939.htm)
      - [无限循环编译](https://blog.csdn.net/weixin_41656968/article/details/80493923)

---

## 命名空间

C++经常需要多个团队合作来完成大型项目。多个团队就常常出现起名重复的问题，C++就提供了命名空间来解决这个问题。

代码如下:

```c++
/*File Atest.h*/

#pragma once
namespace A
{
    void test();
}
```

```c++

/*File Atest.cpp*/

#include<iostream>
#include"Atest.h"
namespace A
{
    void test()
    {
        std::cout << "ATEST" << std::endl;
    }
}
```

```c++
/*File test.h*/

#pragma once
namespace T
{
    void test();
}
```

```c++
/*File test.cpp*/

#include<iostream>
#include"test.h"
namespace T
{
    void test()
    {
        std::cout << "TEST" << std::endl;
    }
}
```

```c++

/*File main.cpp*/

#include <iostream>
#include "test.h"
#include "Atest.h"

int main() {

    A::test();
    T::test();
  return 0;
}

```

从上述代码可以看出`Atest.cpp`和`test.cpp`两个源文件中都定义了`test()`函数，但是编译器
在编译的时候不知道`test()`是要调用哪个文件的`test()`函数，所以得有命名空间加以区分,例如代码中的`A`和`T`
