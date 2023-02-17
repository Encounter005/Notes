# Grammar of strange

<!-- vim-markdown-toc GFM -->

  * [Clsas](#clsas)
  * [函数重载 overload](#函数重载-overload)
  * [内联函数](#内联函数)
  * [(\*)new 关键字](#new-关键字)
    * [1. new 关键字是 C++用来动态分配内存的主要方式](#1-new-关键字是-c用来动态分配内存的主要方式)
    * [2. 内存泄露（常见 bug）](#2-内存泄露常见-bug)
  * [const 关键字](#const-关键字)
  * [(\*\*)auto 关键字](#auto-关键字)
  * [（\*）静态变量，指针和引用](#静态变量指针和引用)
  * [（\*\*）左值，右值，左值引用，右值引用](#左值右值左值引用右值引用)
    * [1. 左值和右值](#1-左值和右值)
    * [2. 引用的分类](#2-引用的分类)
  * [(\*\*)move 函数，临时对象](#move-函数临时对象)
    * [1. move 函数](#1-move-函数)
    * [2. 临时对象](#2-临时对象)
  * [(\*\*)可调用对象](#可调用对象)
    * [1. 函数](#1-函数)
    * [2. 仿函数](#2-仿函数)
    * [3. lambda 表达式](#3-lambda-表达式)
      * [lambda 表达式各个组件介绍](#lambda-表达式各个组件介绍)
* [稀碎的小知识点](#稀碎的小知识点)
  * [memset](#memset)

<!-- vim-markdown-toc -->

## Clsas

类的内部分为两个部分

1. private

   > private 内的变量只能通过类里面的函数进行调用

2. public

   > public 的变量可以在任何地方被调用

```c++
#include <iostream>
using namespace std;

class Player {
private:
public:
  int x, y;
  int speed;

  void Move(int xa, int ya) {
    x += xa * speed;
    y += ya * speed;
  }
};

int main() {
  Player player;
  player.x = 5;
  player.y = 10;
  player.speed = 10;

  player.Move(1, 1);

  cout << player.x << endl;
  cout << player.y << endl;

  return 0;
}

```

struct & class

> 结构体全是 public，class 存在 private

这种写法不咋滴;-;

```c++
#include <iostream>
using namespace std;

class Log {
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
private:
    int m_LogLevel = LogLevelInfo;

public:
  void SetLevel(int level)
  {
    m_LogLevel = level;

  }
  void Error(const char * mess)
  {
    if(m_LogLevel >= LogLevelError)
      cout << "[Error]: " << mess << endl;
  }

  void Info(const char * mess)
  {
    if(m_LogLevel >= LogLevelInfo)
       cout << "[Info]: " << mess << endl;
  }
  void Warn(const char * mess)
  {
    cout << "[Warning]: " << mess << endl;
  }
};

int main() {
  Log log;

  // log.SetLevel(log.LogLevelWarning);//可以改变警告等级
  log.Warn("hello!");
  log.Info("hello!");
  log.Error("hello!");


  return 0;
}

```

---

## 函数重载 overload

如果在一个类中的多个函数，满足如下两点，则这两个函数就构成了重载关系

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

## (\*)new 关键字

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
    delete pi;// ERROR : 不加括号会导致内存泄漏


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

---

## （\*）静态变量，指针和引用

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

---

## （\*\*）左值，右值，左值引用，右值引用

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

## (\*\*)move 函数，临时对象

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

## (\*\*)可调用对象

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

# 稀碎的小知识点

## memset

memset(数组名字，值，数组长度);

- memset 的值只能是 0 或者-1
- 数组长度用 sizeof()来求
