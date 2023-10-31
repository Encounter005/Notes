#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>
template<typename T>
class TD;

template <typename T> class List {
private:
    struct Node {
        T value;
        // 节点的next指针和last指针
        Node *nxt, *lst;
        // 节点的构造函数
        Node( const T v ) {
            nxt   = nullptr;
            lst   = nullptr;
            value = v;
        }
    };

    // 链表的头节点和为节点
    Node *head ;
    Node *tail ;
    // 链表的元素数量
    size_t cnt = 0;

public:
    List( size_t num = 0, T item = 0 );

    List( std::initializer_list<T> &ilist );
    List( List && );
    List( const List & );
    void clear();
    void insert( size_t pos, const T item );

    void insert( const T item );
    void erase( size_t pos );
    bool operator==( const List & );
    bool operator!=( const List & );
    List &operator=( List & );
    List &operator=( List && );
    //重载+=运算符
    List &operator+=( List& other ) {
        return merge(other);
    };
    // 析构函数
    ~List() { clear(); }
    /* @brief 返回头节点
    * 
    * @return 头节点指针
    */
    Node *begin() { return head; };
    /*
     * @brief 返回尾节点
    * 
    * @return 尾节点指针
    */
    Node *end() { return tail; };
    /* @brief 返回头节点
    * 
    * @return 头节点指针，不可以修改
    */
    Node *cbegin() const { return head; };
    /* @brief 返回尾节点
    * 
    * @return 尾节点指针，不可以修改
    */
    Node *cend() const { return tail; };
    // 重载[]运算符 
    T operator[]( size_t pos ) { return find( pos )->value; }
    // @return 链表的大小
    size_t size() const { return cnt; }
private:
    List& merge(List& other);
    /*
     *@brief 寻找节点的位置
     *@param pos 节点位置
     *@return 节点的指针
     * */
    Node *find( size_t pos );
public:
    // 重载<< 用于输出
    friend std::ostream &operator<<( std::ostream &os, List &other ) {
        if ( other.size() == 1 ) {
            os << other.begin()->value << " ";
        } else if ( other.size() == 0 ) {
        } else {
            auto i = other.begin();
            os << i->value << " ";
            i = i->nxt;
            for(; i != other.begin(); i = i->nxt) {
                os << i->value << " ";
            }
        }
        return os;
    }
};

#endif
