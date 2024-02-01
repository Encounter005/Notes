#pragma once

#include <iostream>

template<typename T>
class MyClass{
private:
    T _data;
public:
    template<typename U>
    MyClass(U&& t) : _data(t) {}

    friend std::ostream& operator<< (std::ostream& os , const MyClass& my) {
        os << my._data;
        return os;
    }

    T& GetData() {
        return _data;
    }
};
