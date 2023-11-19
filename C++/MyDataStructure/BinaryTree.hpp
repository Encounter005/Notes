#pragma once
#include <iostream>
#include <memory>
#include <sstream>
#include "Queuev2.hpp"
#include "StackV2.hpp"

template <typename T> class BinaryTree {
private:
    struct node {
        T val;
        node *left, *right;
        node() : left( nullptr ), right( nullptr ), val( 0 ) {}
    };
    node *root;
    void _PreOrder( node *root );
    void _InOrder( node *root );
    void _PostOrder( node *root );
    void _LayerOrder( node *root );
    void _PreOrder_NoRef( node *root );
    void _InOrder_NoRef( node *root );
    void _PostOrder_NoRef( node *root );
    template <typename U>
    void _Create(
        const std::string &ssin, U &&ref, size_t& index, node *&subtree );
    void _CreateCopy(node* src , node* &dest);
    void _Clear( node *root );
    size_t _Depth( node *root );
    size_t _Size( node *root );


public:
    BinaryTree() : root( nullptr ) {}
    template <typename U> BinaryTree( const std::string &s, U &&ref ) {
        root = nullptr;
        size_t c = 0;
        if ( s.size() ) {
            _Create( s, std::forward<U>( ref ), c, root );
        }
    }
    ~BinaryTree() { _Clear( root ); }
    BinaryTree(const BinaryTree&);
    BinaryTree(BinaryTree&&) noexcept;
    BinaryTree& operator=(const BinaryTree&);
    BinaryTree& operator=(BinaryTree&& other) noexcept;

    void PreOrder() { _PreOrder( root ); }
    void InOrder() { _InOrder( root ); }
    void PostOrder() { _PostOrder( root ); }
    void LayerOrder() { _LayerOrder( root ); }
    void PreOrder_NoRef() { _PreOrder_NoRef( root ); }
    void InOrder_NoRef() { _InOrder_NoRef( root ); }
    void PostOrder_NoRef() { _PostOrder_NoRef( root ); }

    void clear() { _Clear( root ); };
    size_t depth() { return _Depth( root ); }
    size_t size() { return _Size( root ); }
    bool empty() { return root == nullptr; }
};


template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other) {
    if(other.root) {
        _CreateCopy(other.root , root);
    } else {
        root = nullptr;
    }
}

template<typename T>
BinaryTree<T>::BinaryTree(BinaryTree&& other) noexcept {
    root = other.root;
    other.root = nullptr;
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) {
    if(this != &other) {
        this->clear();
        this->root = new node();
        _CreateCopy(other.root , this->root);
    }
    return *this;
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T>&& other) noexcept {
    if(this != &other) {
        this->clear();
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template <typename T>
template <typename U>
void BinaryTree<T>::_Create(
    const std::string &s, U &&ref, size_t& index, node *&subtree ) {
    subtree = nullptr;
    if ( index == s.size() || s[index] == ref ) {
        return ;
    } 
    subtree = new node();
    subtree->val = s[index++];
    _Create(s, std::forward<U>(ref) , index , subtree->left);
    _Create(s , std::forward<U>(ref) , ++index , subtree->right);
}

template<typename T>
void BinaryTree<T>::_CreateCopy(node* src, node*& dest) {
    if(src) {
        dest = new node();
        dest->val = src->val;
        _CreateCopy(src->left , dest->left);
        _CreateCopy(src->right , dest->right);
    } else {
        dest = nullptr;
    }
}

template <typename T> void BinaryTree<T>::_PreOrder( node *root ) {
    if ( root != nullptr ) {
        std::cout << root->val << " ";
        _PreOrder( root->left );
        _PreOrder( root->right );
    }
    return;
}

template <typename T> void BinaryTree<T>::_PreOrder_NoRef( node *root ) {
    Stack<decltype( root )> stk;
    auto cur = root;
    while ( cur || !stk.empty() ) {
        if ( cur ) {
            std::cout << cur->val << " ";
            stk.emplace( cur );
            cur = cur->left;
        } else {
            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }
    }
}

template <typename T> void BinaryTree<T>::_InOrder( node *root ) {
    if ( root != nullptr ) {
        _InOrder( root->left );
        std::cout << root->val << " ";
        _InOrder( root->right );
    }
    return;
}

template <typename T> void BinaryTree<T>::_InOrder_NoRef( node *root ) {
    Stack<decltype( root )> stk;
    auto cur = root;
    int cnt  = 0;
    while ( cur || stk.size() ) {
        if ( cur ) {
            stk.emplace( cur );
            cur = cur->left;

        } else {
            auto t = stk.top();
            std::cout << t->val << " ";
            stk.pop();
            cur = t->right;
        }
    }
}

template <typename T> void BinaryTree<T>::_PostOrder( node *root ) {
    if ( root != nullptr ) {
        _PostOrder( root->left );
        _PostOrder( root->right );
        std::cout << root->val << " ";
    }
    return;
}

template <typename T> void BinaryTree<T>::_PostOrder_NoRef( node *root ) {
    Stack<decltype(root)> stk;
    auto cur  = root;
    node *pre = nullptr;
    stk.push( root );
    while ( !stk.empty() ) {
        cur = stk.top();
        if ( ( cur->left == nullptr and cur->right == nullptr ) or
             ( pre == nullptr and
                 ( pre->left == cur->left and pre->right == cur->right ) ) ) {
            std::cout << cur->val << " ";
            pre = cur;
            stk.pop();
        } else {
            if ( cur->right ) {
                stk.push( cur->right );
            }
            if ( cur->left ) {
                stk.push( cur->left );
            }
        }
    }
}

template <typename T> void BinaryTree<T>::_LayerOrder( node *root ) {
    Queue<decltype( root )> q;
    q.push( root );
    while ( !q.empty() ) {
        auto t = q.front();
        q.pop();
        std::cout << t->val << " ";
        if ( t->left ) {
            q.push( t->left );
        }
        if ( t->right ) {
            q.push( t->right );
        }
    }
}
template <typename T> void BinaryTree<T>::_Clear( node *root ) {
    if ( root != nullptr ) {
        Queue<decltype( root )> q;
        q.push( root );
        while ( !q.empty() ) {
            auto t = q.front();
            q.pop();
            if ( t->left ) {
                q.push( t->left );
            }
            if ( t->right ) {
                q.push( t->right );
            }
            delete t;
        }
    }
}
template <typename T> size_t BinaryTree<T>::_Size( node *root ) {
    size_t cnt = 0;
    if ( root != nullptr ) {
        Queue<decltype( root )> q;
        q.push( root );
        while ( !q.empty() ) {
            auto t = q.front();
            cnt++;
            q.pop();
            if ( t->left ) {
                q.push( t->left );
            }
            if ( t->right ) {
                q.push( t->right );
            }
        }
    }
    return cnt;
}

template <typename T> size_t BinaryTree<T>::_Depth( node* root ) {
    if(root == nullptr) {
        return 0;
    } else {
        return std::max(_Depth(root->left) , _Depth(root->right)) + 1;
    }
}
