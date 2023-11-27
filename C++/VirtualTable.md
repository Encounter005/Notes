# 虚函数表原理和类成员内存分布

[源连接](https://llfc.club/category?catid=225RaiVNI8pFDD5L4m807g7ZwmF#!aid/2CmcOeP6BZMbtNiglPTkbmnpb73)

## 不可定义为虚函数的函数
> 类的静态函数和构造函数

静态函数的目的是通过类名+函数名访问类中的`static`变量，或者通过对象调用`static`函数实现对`static`成员变量的读写，要求内存中只有一份数据。而虚函数在子类中重写，并且通过多态机制实现动态调用，在内存中需要保存不同的重写版本。

构造函数的作用是构造对象，而虚函数的调用是在对象已经构造完成，并且通过调用时动态绑定。动态绑定是因为每个类对象内部都有一个指针，指向虚函数表的首地址。而且虚函数、类的成员函数，`static`成员函数都不是存储在类对象中，而是在内存中只保留一份。

## 将析构函数定义为虚函数的作用

类的构造函数不能定义为虚函数，析构函数可以定义为虚函数，这样当我们delete一个指向子类对象的基类指针时可以达到调用子类析构函数的作用，从而动态释放内存。

```c++
#include <iostream>

class VirtualTableA {
public:
    virtual ~VirtualTableA() { std::cout << "VirtualTableA Destructor\n"; }
    virtual void print() { std::cout << "print VirtualTable A\n"; }
};

class VirtualTableB : public VirtualTableA {
public:
    ~VirtualTableB() { std::cout << "VirtualTableB Destructor\n"; }
    virtual void print() override;
};

void VirtualTableB::print() { std::cout << "print VirtualTable B\n"; }

// 通过一个基类指针来调用子类的虚函数
void useTable( VirtualTableA *pa ) {
    // 实现动态调用
    pa->print();
}

void destructVirtualTable() {
    VirtualTableA *pa = new VirtualTableB();
    useTable( pa );
    delete pa;
}
int main() { 
    destructVirtualTable();
    
    return 0; 
}
```
在上面的例子中我们在`destructVirtualTable`函数中定义了一个基类`VirtualTableA`类型的指针，这个指针指向new的`VirtualTableB`类型的对象。然后这个基类对象`pa`传给`useTable`函数，这样根据多态原理调用`VirtualTableB`的print函数，然后在执行`delete`。

注意，如果pa的析构函数不写成虚函数，那么就只会调用`VirtualTableA`的析构函数，不会调用`VirtualTableB`的析构函数，这样直接造成了内存泄漏。

在实际项目中我们常常会用基类指针接受子类对象来通过多态的方式调用子类函数，为了方便delete基类指针也要释放子类空间。所以要将析构函数设置为虚函数。

## 虚函数表的原理


