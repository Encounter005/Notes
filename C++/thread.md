# C++ Thread

## 线程管理

### 线程的归属权

每个线程都有其归属权，也就是说归属给每个变量管理

```c++

void func() {

}

std::thread t1(func);

```

`t1`是一个线程变量，管理一个线程，该线程执行`func()`对于`std::thread`C++不允许拷贝构造和拷贝赋值，所以只能通过移动和局部变量返回的方式将线程变量管理权转移给其他变量管理。

例如下面的例子

```c++
#include <iostream>
#include <thread>
#include <chrono>

namespace {
void func1() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void func2() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

}; // namespace
int main() {
    //1. t1绑定函数func1()
    std::thread t1(func1);
    //2. 转移t1的管理的线程给t2，转移后t1无效
    std::thread t2 = std::move(t1);
    //3. t1绑定函数func2()
    t1 = std::thread(func2);
    //4. 新建一个线程t3
    std::thread t3;
    //5. 转移t2管理的线程给t3，，
    t3 = std::move(t2);
    //6. 转移t3管理的线程给t1
    t1 = std::move(t3);
    //BUG:不可以将一个线程的管理权交给一个已经绑定线程的变量，
    //否则会触发线程的terminate函数引发崩溃
    // t1 = std::move(t3);
    std::this_thread::sleep_for(std::chrono::seconds(2000));

    return 0;
}

```
