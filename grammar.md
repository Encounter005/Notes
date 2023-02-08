# Grammar of strange

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




## new关键字

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


### 2. 内存泄露（常见bug）

1. 内存泄露的后果
    
    * 内存泄露会导致堆内存的逐渐被占用，最终内存用完程序崩溃。常见的情况就是项目测试没问题，上线几天就炸了。然后就会非常麻烦，排查困难，损失很大。
    * 内存泄露是最严重的错误之一，程序不怕报错，就怕一开始运行的好好的，突然就出现了莫名其妙的错误。

2. 检测工具使用

[valgrind](https://zhuanlan.zhihu.com/p/75416381)

3. 解决方法

    1. 智能指针
    2. 异常处理

***


## auto 关键字


关于输出auto推断的变量类型 -- boost库

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

1. auto只能推断出类型，引用不是类型，所以auto无法推断出引用，要使用引用只能自己加引用符号
2. auto关键字在推断引用的类型时:会直接将引用替换为引用指向的对象。其实引用一直是这样的，引用不是对象，任何使用引用的地方都可以直接替换成引用指向的对象。

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


3. auto关键字在推断类型时，如果没有引用符号，会忽略值类型的const修饰，而保留修饰指向对象的const，典型的就是指针。


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


4. auto关键字在推断类型时，如果有了引用符号，那么值类型的const和修饰指向对象的const都会保留。


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

5. 当然，我们可以在auto前面加上const，这样永远都有const的含义。

6. auto不会影响编译速度，甚至会加快编译速度。因为编译器在处理XX a = b时，当XX是传统类型时，编译期需要检查b的类型是否可以转化为XX。当XX为auto时，编译期可以按照b的类型直接给定变量a的类型，所以效率相差不大，甚至反而还有提升。

7. （*）最重要的一点，就是auto不要滥用，对于一些自己不明确的地方不要乱用auto，否则很可能出现事与愿违的结果，使用类型应该安全为先。

8. （*）auto主要用在与模板相关的代码中，一些简单的变量使用模板常常导致可读性下降，经验不足还会导致安全性问题。


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
***

## （*）静态变量，指针和引用

> 变量的存储位置有三种，分别是静态变量区，栈区，堆区。

静态变量区在编译时就已经确定地址，存储全局变量与静态变量。

指针都是存储在栈上或堆上，不管在栈上还是堆上，都一定有一个地址。
本质上说，指针和普通变量没有区别。
在32位系统中，int变量和指针都是32位。指针必须和“&”，“*”这两个符号一起使用才有意义。
&a代表的a这个变量的地址，a代表的a对应地址存储的值，*a代表对应地址存储的值作为地址对应的值.

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
所以指针才可以灵活的操作内存，但这也带来了严重的副作用，比如指针加加减减就可以操作内存，所以引用被发明了，引用就是作用阉割的指针（可以视为“类型*const”，所以引用必须上来就赋初值，不能设置为空），对引用来说，编译器不将其视作对象，操作引用相当于操作引用指向的对象。也就从根本是杜绝了引用篡改内存的能力。



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


***

## （**）左值，右值，左值引用，右值引用

### 1. 左值和右值

C++任何一个对象要么是左值要么是右值

例如```int i = 10```, ```i```和```10```都是对象

左值：拥有地址属性的对象就叫左值，左值来源于C语言的说法，能放在"="左边的就是左值
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

2. const左值引用：可以对常量起别名，可以绑定左值和右值


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


4. 万能引用


# 稀碎的小知识点

## memset

memset(数组名字，值，数组长度);

- memset 的值只能是 0 或者-1
- 数组长度用 sizeof()来求
