# C++ primer -- some notes

<!--toc:start-->
- [C++ primer -- some notes](#c-primer-some-notes)
  - [1 Getting start](#1-getting-start)
    - [file type](#file-type)
    - [literal](#literal)
    - [comment](#comment)
    - [flow of control](#flow-of-control)
  - [2 Variables and Basic Types（变量和基本类型）](#2-variables-and-basic-types变量和基本类型)
  - [3 Separate Compliation（复合类型）](#3-separate-compliation复合类型)
  - [Chapter 12 Dynamic Memory](#chapter-12-dynamic-memory)
<!--toc:end-->

[C++ primer](https://www.bilibili.com/video/BV1B8411K71w/?spm_id_from=333.999.0.0)


## 1 Getting start

function
* return
* name
* parameter list
* function body

> binary program -> main()

main function
* entry point

java ->
```java
JavaProgram
public static void main(String[] , args) {

  }

Javac javaProgram -- a = 3 b = 4
```


main return value 表明了程序运行的结果

```c++

#include<iostream>
using namespace std;


int function(int argument)
{
  cout << "hello world" << argument << endl;
  return 1;
}

/*
NOTE :  agrument count
        argument vector
*/

int main(int argc , char** argv)
{
  for(int i = 0; i < argc; i ++)
  {
    cout << argv[i] << endl;
  }

  function(100);
  return 0;
}
```



### file type
cc , cxx , cpp , cp
.h header

***

### literal

string literal = "abc" , "hello world"
integer literal

***

### comment
//  

/**/
***

### flow of control

```cpp
flow1 -> for
int sum = 0;
for(int i = 0; i < 100; i ++)    sum += i;
sum = 5050;

flow2 -> while

int sum = 0;
int i =0;
while(i < 100)
{
  sum += i;
  i ++;
}

flow3 -> if

if(condition == true)
{

}

```


## 2 Variables and Basic Types（变量和基本类型）


int
long
bool -> true/false
float
double

sign/unsigned
5 -5

int -> long
-2^31 ^ 2^31 - 1
-2^63 ^ 2^63 - 1
long -> int

> type conversion

long a = 31L;


## 3 Separate Compliation（复合类型）
> Compound Type

* reference(引用)
  * bind to a local variable
  * can not bind literal / constant

```c++
#include<iostream>
using namespace std;
int main(int argc , char** argv)
{
  int local_price = 12;
  int &replace_price = local_price;
  
  string s = "hello";
  string &c = "hello"; //""
  
  cout << &replace_price << endl;
  cout << &local_price << endl;

  for(int i = 0; i < 10; i ++)
  {
    local_price = i;
    cout << replace_price << endl;
  }
  return 0;
}

```


* pointer(指针)
```c++
#include<iostream>
using namespace std;

int main(int argc , char** argv)
{
  int a = 5;
  int *pa = &a;
  cout << a << endl;
  cout << *pa << endl;

  *pa = 20;
  cout << a << endl;
  cout << *pa << endl;

  return 0;
}

```

ref VS pointer
* ref -> initialize


## Chapter 12 Dynamic Memory

> 没有什么特别需求，尽量用`unique_ptr`

```c++
#include <iostream>
#include <memory>

void func() {
    std::shared_ptr<int> p = std::make_shared<int>(42);
    std::shared_ptr<int> p2(p);

    std::cout << p.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;

    {
        std::shared_ptr<int> p3(p);
        std::cout << p.use_count() << std::endl;
        std::cout << p3.use_count() << std::endl;
    } // NOTE: p3 is destoryed
    
    std::cout << p.use_count() << std::endl;
}

int main() {
    func();

    return 0;
}

```

```c++
#include <iostream>
#include <memory>


class A {
public:
    A(int a_ , const std::string& b_) : a(a_) , b(b_) {
        std::cout << "In Constructor" << std::endl;
    }

    ~A() {
        std::cout << "In destructor" << std::endl;
    }
private:
    int a;
    std::string b;
};

void func() {
    std::cout << "in functions begin" << std::endl;
    std::shared_ptr<A> p = std::make_shared<A>(1 , "awdjawkd");
    std::cout << "in functions end" << std::endl;
}

int main() {
    func();

    return 0;
}
```



