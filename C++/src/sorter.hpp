#pragma once
#include <thread>
#include <chrono>
#include <future>
#include <list>
#include <vector>
#include "Stack_Thread_Safe.hpp"
#include <algorithm>
#include <atomic>
#include "Single_TV2.hpp"

class ParrelQuickSortWrapper : public Single_T<ParrelQuickSortWrapper> {
public:
template <typename T> 
    static std::list<T> parallel_quick_sort( std::list<T> input ) {
    if ( input.empty() ) {
        return input;
    }
    sorter<T> s;
    return s.do_sort( input );
}

private:
template <typename T> struct sorter {

    // 需要排序的数据段
    struct chunk_to_sort {
        std::list<T> data; // 存排序的数据
        std::promise<std::list<T>>
            promise; // 设置一个promise对象用于实现异步任务，
        // 这个promise对象的get_future()方法返回一个future对象，用于在异步任务完成时得到排序结果
    };

    std::vector<std::thread> threads;
    unsigned const max_threads_count;
    std::atomic<bool>
        end_of_data; // 原子变量，当值是true时，表示数据已经全部处理完了
    Stack_Thread_Safe<chunk_to_sort> chunks; // 将需要排序的数据块用栈存储起来
    sorter()
        : max_threads_count( std::thread::hardware_concurrency() - 1 ),
          end_of_data( false ) {}
    ~sorter() {
        end_of_data = true;
        for ( auto &i : threads ) {
            i.join();
        }
    }

    //@brief do_sort函数是排序算法的主函数，它将数据块进行排序
    std::list<T> do_sort( std::list<T> &chunk_data ) {
        if ( chunk_data.empty() ) {
            return chunk_data;
        }

        std::list<T> result; // 存储排序结果
        result.splice( result.begin(), chunk_data,
            chunk_data.begin() ); // 将chunk_data的第一个元素移动到result的头部
        typename std::list<T>::iterator divide_point = std::partition(
            chunk_data.begin(), chunk_data.end(), [&]( const T &val ) {
                return val < *result.begin();
            } ); // divide_point指向第一个大于等于*result.begin()的元素

        chunk_to_sort
            new_lower_chunks; // new_lower_chunks用于存储小于divide_point这一段区间的待排序数据块
        new_lower_chunks.data.splice( new_lower_chunks.data.end(), chunk_data,
            chunk_data.begin(), divide_point );
        std::future<std::list<T>> new_lower =
            new_lower_chunks.promise
                .get_future(); // new_lower是用于存储小于divide_point这一段区间的排序结果
        chunks.push( std::move( new_lower_chunks ) );
        if ( threads.size() < max_threads_count ) {
            threads.push_back( std::thread( &sorter<T>::sort_thread, this ) );
        }

        std::list<T> new_higher( do_sort(
            chunk_data ) ); // new_higher是用于存储大于divide_point这一段区间的排序结果
        result.splice( result.end(), new_higher );

        while ( new_lower.wait_for( std::chrono::seconds( 0 ) ) !=
                std::future_status::ready ) {
            try_to_sort();
        }
        result.splice( result.begin(), new_lower.get() );
        return result;
    }

    //@brief 函数将数据排序并设置一个promise对象，用于异步任务完成后得到排序结果
    void sort_chunk( std::shared_ptr<chunk_to_sort> const &chunk ) {
        chunk->promise.set_value( do_sort( chunk->data ) );
    }

    //@brief 取出需要排序数据块的栈顶元素，如果不是空指针就会执行sort_chunk函数
    void try_to_sort() {
        std::shared_ptr<chunk_to_sort> res = chunks.try_pop();
        if ( res ) {
            sort_chunk( res );
        }
    }

    //@brief
    //sort_thread函数是一个线程函数，它将从chunks中取出需要排序的数据块，并将其传递给sort_chunk函数进行排序
    void sort_thread() {
        while ( !end_of_data ) {
            try_to_sort();
            std::this_thread::yield();
        }
    }
};
};



