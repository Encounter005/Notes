#ifndef __LIST_HPP
#define __LIST_HPP

#include "List.h"

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
