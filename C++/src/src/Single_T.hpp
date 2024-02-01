#pragma once
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

template<typename T>
class Single_T;

template<typename T>
class SafeDeletor {
public:
    void operator()(T* s) {
        std::cout << "this is safe deletor operator()\n";
        delete s;
    }
};

template<typename T>
void SafeDeletorFunc(T* s) {
    std::cout << "this is safe deletor func\n";
    delete s;
}

template<typename T>
class Single_T {
protected:
    Single_T() = default;
    ~Single_T() {
        std::cout << "this is single template deletor\n";
    }
    Single_T(const Single_T&) = delete;
    Single_T& operator=(const Single_T&) = delete;
    friend class SafeDeletor<T>;
    friend void SafeDeletorFunc<T>(T* s);
public:
    static std::shared_ptr<T> getInstance() {
        if(single != nullptr) {
            return single;
        }
        Lock.lock();
        if(single != nullptr) {
            Lock.unlock();
            return single;
        }
        // NOTE:额外指定删除器
        // single = std::shared_ptr<T>(new T, SafeDeletor<T>());
        // NOTE:额外指定删除函数
        single = std::shared_ptr<T>(new T , SafeDeletorFunc<T>);
        Lock.unlock();
        return single;
        
    }
private:
    static std::shared_ptr<T> single;
    static std::mutex Lock;
};
// NOTE: 模板类的static成员要放在hpp文件内初始化

template<typename T>
std::shared_ptr<T> Single_T<T>::single = nullptr;
template<typename T>
std::mutex Single_T<T>::Lock;
