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
        Node *nxt, *lst;
        Node( const T v ) {
            nxt   = nullptr;
            lst   = nullptr;
            value = v;
        }
    };

    Node *head ;
    Node *tail ;
    size_t cnt = 0;

public:
    List();
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
    ~List() { clear(); }
    Node *begin() { return head; };
    Node *end() { return tail; };
    Node *cbegin() const { return head; };
    Node *cend() const { return tail; };
    Node *find( size_t pos );
    T operator[]( size_t pos ) { return find( pos )->value; }
    size_t size() const { return cnt; }
    List& merge(List& other);
    friend std::ostream &operator<<( std::ostream &os, List &other ) {
        if ( other.size() == 1 ) {
            os << other.begin()->value << " ";
        } else if ( other.size() == 0 ) {
            return os;
        } else {
            auto i = other.begin();
            os << i->value << " ";
            i = i->nxt;
            for(; i != other.begin(); i = i->nxt) {
                os << i->value << " ";
            }
            return os;
        }
    }
};

#endif
