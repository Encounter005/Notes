#pragma once

#include <thread>
#include <climits>
#include <mutex>
#include <thread>
#include <exception>
#include <stdexcept>

class hierarchial_mutex{
public:
    explicit hierarchial_mutex(unsigned long value) : _hierarchy_value(value) , _previous_hierarchy_value(0) {}
    hierarchial_mutex(const hierarchial_mutex&) = delete;
    hierarchial_mutex& operator=(const hierarchial_mutex&) = delete;
    
    // @brief: 加锁函数，先检查是否违反当前层级值，如果没有，可以加锁并且更新线程的层级值
    void lock() {
        check_for_hierarchy_violation();
        _internal_mutex.lock();
        update_hierarchy_value();
    }
    
    // @brief: 解锁函数, 如果线程的层级值和当前层级值不一致，就抛出异常，否则先更新线程的层级为上一层的层级值，再解锁
    void unlock() {
        if(_this_thread_hierarchy_value != _hierarchy_value) {
            throw std::logic_error("mutex hierarchy violated");
        } 
        _this_thread_hierarchy_value = _previous_hierarchy_value;
        _internal_mutex.unlock();
    }
    
    // @brief: 尝试加锁函数，先检查是否违反当前层级值，再检查锁是否可以加，最后在更新线程的层级值
    bool trylock() {
        check_for_hierarchy_violation();
        if(!_internal_mutex.try_lock()) {
            return false;
        }
        update_hierarchy_value();
        return true;
    }
    
private:
    std::mutex _internal_mutex;
    // NOTE: 当前层级值
    unsigned long const _hierarchy_value;
    // NOTE: 上一次层级值
    unsigned long _previous_hierarchy_value;
    // NOTE: 本线程记录的层级值
    static thread_local unsigned long _this_thread_hierarchy_value;
    // NOTE: thread_local 关键字修饰的变量具有线程周期，这些变量在线程开始时被生成，在线程结束时被销毁，并且每一个线程都共享同一个的变量
    
    // @brief: 检查当前线程是否违反当前层级
    void check_for_hierarchy_violation() {
        if(_this_thread_hierarchy_value <= _hierarchy_value) {
            throw std::logic_error("mutex hierarchy violated");
        }
    }

    // @brief: 更新线程的层级值
    void update_hierarchy_value() {
        _previous_hierarchy_value = _this_thread_hierarchy_value;
        _this_thread_hierarchy_value = _hierarchy_value;
    }

};

thread_local unsigned long hierarchial_mutex::_this_thread_hierarchy_value = ULONG_MAX;
