#pragma once
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

template<typename T>
class Single_T {
protected:
    Single_T() = default;
    ~Single_T() {
        std::cout << "this is single template deletor\n";
    }
    Single_T(const Single_T<T>&) = delete;
    Single_T& operator=(const Single_T<T>&) = delete;
    static std::shared_ptr<T> single;
public:
    static std::shared_ptr<T> getInstance() {
        // NOTE: call_once可以保证在多线程的情况下，里面的function只被执行一次。
        static std::once_flag s_flag;
        std::call_once(s_flag , [&](){
            single = std::shared_ptr<T>(new T);
        });
        return single;
    }
};
// NOTE: 模板类的static成员要放在hpp文件内初始化

template<typename T>
std::shared_ptr<T> Single_T<T>::single = nullptr;
