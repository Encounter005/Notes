#ifndef __LIST_HPP
#define __LIST_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>
template <typename T> class TD;

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
    Node *head;
    Node *tail;
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
    // 重载+=运算符
    List &operator+=( List &other ) { return merge( other ); };
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
    List &merge( List &other );
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
            for ( ; i != other.begin(); i = i->nxt ) {
                os << i->value << " ";
            }
        }
        return os;
    }
};

/* 构造函数
 *
 * @param num 链表的大小， 元素的值
 */
template <typename T> List<T>::List( size_t num, T item ) {
    head = tail = nullptr;
    if ( num == 0 ) {
        return;
    }
    while ( num-- ) {
        insert( item );
    }
}

/*
 *  构造函数
 *
 *  @param ilist 列表
 * */
template <typename T> List<T>::List( std::initializer_list<T> &ilist ) {
    head = tail = nullptr;
    cnt         = 0;
    if ( ilist.size() == 0 ) {
        return;
    }

    for ( const auto &elem : ilist ) {
        insert( elem );
    }
}

/*
 * 清空函数
 *
 * @brief 删除链表所有节点
 * */
template <typename T> void List<T>::clear() {
    if ( head != nullptr ) {
        for ( auto i = head; i != tail; ) {
            auto p = i;
            i      = i->nxt;
            delete p;
        }
        delete tail;
    }
    head = nullptr;
    tail = nullptr;
    cnt  = 0;
}

template <typename T> bool List<T>::operator==( const List &other ) {
    return this->head == other.head && this->tail == other.tail &&
           this->cnt == other.cnt;
}
template <typename T> bool List<T>::operator!=( const List &other ) {
    return this->head != other.head || this->tail != other.tail ||
           this->cnt != other.cnt;
}

// 复制构造函数
template <typename T> List<T>::List( const List &other ) {
    head = tail = nullptr;
    cnt         = 0;
    for ( size_t i = 0; i < other.size(); i++ ) {
        insert( other[i] );
    }
}

// 移动构造函数
template <typename T> List<T>::List( List &&other ) {
    head = tail = nullptr;
    cnt         = 0;
    for ( size_t i = 0; i < other.size(); i++ ) {
        insert( other[i] );
    }
}

// 复制运算符
template <typename T> List<T> &List<T>::operator=( List &other ) {
    if ( this == &other ) {
        return *this;
    } else {
        clear();
        for ( size_t i = 0; i < other.size(); i++ ) {
            insert( other[i] );
        }
    }
    return *this;
}

// 移动运算符
template <typename T> List<T> &List<T>::operator=( List &&other ) {
    if ( this == &other ) {
        return *this;
    } else {
        clear();
        for ( size_t i = 0; i < other.size(); i++ ) {
            insert( other[i] );
        }
    }
    return *this;
}

/* 插入函数
 *
 * @brief 在指定位置插入元素
 * @param pos 位置 item 元素
 * */
template <typename T> void List<T>::insert( size_t pos, const T item ) {
    if ( pos == cnt ) {
        insert( item );
        return;
    }
    auto i    = find( pos );
    Node *ptr = new Node( item );
    auto pre  = i->lst;
    pre->nxt  = ptr;
    i->lst    = ptr;
    ptr->lst  = pre;
    ptr->nxt  = i;

    if ( pre == tail ) {
        head = ptr;
    }
    cnt++;
}

/*
 * 插入函数
 *
 * @brief 在尾节点后面插入新节点
 * @param item 元素
 * */
template <typename T> void List<T>::insert( const T item ) {
    Node *ptr = new Node( item );
    if ( head == nullptr ) {
        head = tail = ptr;
        head->nxt   = tail;
        tail->lst   = head;
    } else {
        tail->nxt = ptr;
        ptr->lst  = tail;
        tail      = ptr;
    }
    tail->nxt = head;
    head->lst = tail;
    cnt++;
}

template <typename T> typename List<T>::Node *List<T>::find( size_t pos ) {
    if ( pos >= cnt ) {
        throw "pos is too large!\n";
    }

    auto i = head;
    while ( pos-- ) {
        i = i->nxt;
    }
    return i;
}

/*
 *
 * 删除函数
 *
 * @brief 删除节点
 * @param pos 节点位置
 *
 * */
template <typename T> void List<T>::erase( size_t pos ) {
    auto i = find( pos );
    if ( i == head ) {
        auto p    = head->nxt;
        tail->nxt = p;
        p->lst    = tail;
        head      = p;
        delete i;
    } else if ( i == tail ) {
        auto p    = tail->lst;
        p->nxt    = head;
        head->lst = p;
        tail      = p;
        delete i;
    } else {
        auto front  = i->lst;
        front->nxt  = i->nxt;
        i->nxt->lst = front;
        delete i;
    }
    cnt--;
}

/*
 * 合并函数
 *
 * @brief 将两个链表有序合并
 * @param 要合并的链表
 *
 * */
template <typename T> List<T> &List<T>::merge( List<T> &other ) {
    if ( head == nullptr ) {
        *this = other;
    }

    List<T> res( 0 );

    size_t l = 0, r = 0;
    while ( l < this->size() && r < other.size() ) {
        if ( ( *this )[l] <= other[r] ) {
            res.insert( ( *this )[l++] );
        } else {
            res.insert( other[r++] );
        }
    }

    if ( l == this->size() && r == other.size() ) {
        *this = res;
    } else {
        if ( l == this->size() ) {
            for ( ; r < other.size(); r++ ) {
                res.insert( other[r] );
            }
        } else {
            for ( ; l < this->size(); l++ ) {
                res.insert( ( *this )[l] );
            }
        }
        *this = res;
    }

    return *this;
}

#endif
