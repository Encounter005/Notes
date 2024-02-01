/*
 *  filename: BinaryTree.hpp
 *
 * */

#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include "Queuev2.hpp"
#include "StackV2.hpp"



template <typename T> class BinaryTree {
private:
    // 定义叶子节点
    struct node {
        T val;
        node *left, *right;
        // 无参构造函数
        node() : left( nullptr ), right( nullptr ), val( 0 ) {}
    };
    // 根节点
    node *root;
    // 前序遍历递归
    void _PreOrder( node *root );
    // 中序遍历递归
    void _InOrder( node *root );
    // 后续遍历递归
    void _PostOrder( node *root );
    // 层序遍历
    void _LayerOrder( node *root );
    // 前序遍历非递归
    void _PreOrder_NoRef( node *root );
    // 中序遍历非递归
    void _InOrder_NoRef( node *root );
    // 后序遍历非递归
    void _PostOrder_NoRef( node *root );
    template <typename U>
    // @brief: 创建节点函数
    // @param: const string& s 给定的序列 
    // @param: U&& ref 终止符 
    // @param: size_t index 下标 
    // @param: node*& subtree 要创建的节点指针
    void _Create(
        const std::string &s, U &&ref, size_t &index, node *&subtree );
    // @brief: 复制节点
    // @param: node* src 要被复制的节点 node*& dest 复制到新的节点
    void _CreateCopy( node *src, node *&dest );
    // @brifef: 释放内存
    void _Clear( node *root );
    // @brief: 求树深度
    size_t _Depth( node *root );
    // @brief: 求叶子节点的数量
    size_t _Size( node *root );
    // @brief: 判断二叉树是否为完全二叉树
    bool _isCompleteBinaryTree( node *root );
    // @brief: 通过后序遍历和中序遍历构建二叉树
    // @param: std::unordered_map<T, size_t>& pos 中序遍历的索引 
    // @param: std::vector<T>& post 后续遍历
    // @param: node*& subtree 叶子节点的指针 
    // @param: size_t il 中序遍历的左边界
    // @param: size_t ir 中序遍历的右边界 
    // @param: size_t pl 后序遍历的左边界 
    // @param: size_t pr 后序遍历的右边界
    void _CreateWithPostAndMid(std::unordered_map<T , size_t>& pos , const std::vector<T>& post , node*& subtree, size_t il , size_t ir , size_t pl , size_t pr);

public:
    // 无参构造函数
    BinaryTree() : root( nullptr ) {}
    // @brief: 有参构造函数
    // @param: string &s 给定的序列 U &&ref 终止符
    template <typename U> BinaryTree( const std::string &s, U &&ref ) {
        root     = nullptr;
        size_t c = 0;
        if ( s.size() ) {
            _Create( s, std::forward<U>( ref ), c, root );
        }
    }
    // @brief: 根据后序遍历和中序遍历构造二叉树
    // @param: std::unordered_map<T , size_t> &pos 中序遍历的索引 
    // @param: std::vector<T> post 后序遍历
    BinaryTree(std::unordered_map<T , size_t>& pos , std::vector<T>& post) {
        root = nullptr;
        _CreateWithPostAndMid(pos , post , root ,  0 , post.size() - 1 , 0 , post.size() - 1);
    }
    // 析构函数
    ~BinaryTree() { _Clear( root ); }
    // 复制构造函数
    BinaryTree( const BinaryTree & );
    // 移动构造函数
    BinaryTree( BinaryTree && ) noexcept;
    // 复制运算符
    BinaryTree &operator=( const BinaryTree & );
    // 移动运算符
    BinaryTree &operator=( BinaryTree &&other ) noexcept;

    // @brief: 输出先序遍历
    void PreOrder() { _PreOrder( root ); }
    // @brief: 输出中序遍历
    void InOrder() { _InOrder( root ); }
    // @brief: 输出后序遍历
    void PostOrder() { _PostOrder( root ); }
    // @brief: 输出层序遍历
    void LayerOrder() { _LayerOrder( root ); }
    void PreOrder_NoRef() { _PreOrder_NoRef( root ); }
    void InOrder_NoRef() { _InOrder_NoRef( root ); }
    void PostOrder_NoRef() { _PostOrder_NoRef( root ); }
    
    // @brief: 清空函数
    // @function： 清空二叉树并释放内存
    void clear() { _Clear( root ); };
    // @brief: 返回二叉树的深度
    // @return: size_t
    size_t depth() { return _Depth( root ); }
    // @brief: 返回二叉树叶子节点的数量
    // @return: size_t
    size_t size() { return _Size( root ); }
    // @brief: 检测二叉树是否为空
    // @return: bool
    bool empty() { return root == nullptr; }
    // @brief: 判断二叉树是否是完全二叉树
    // @return: bool
    bool isCompleteBinaryTree() {
        return _isCompleteBinaryTree(root);
    }
};

template <typename T> BinaryTree<T>::BinaryTree( const BinaryTree &other ) {
    if ( other.root ) {
        _CreateCopy( other.root, root );
    } else {
        root = nullptr;
    }
}

template <typename T> BinaryTree<T>::BinaryTree( BinaryTree &&other ) noexcept {
    root       = other.root;
    other.root = nullptr;
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=( const BinaryTree<T> &other ) {
    if ( this != &other ) {
        this->clear();
        this->root = new node();
        _CreateCopy( other.root, this->root );
    }
    return *this;
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=( BinaryTree<T> &&other ) noexcept {
    if ( this != &other ) {
        this->clear();
        root       = other.root;
        other.root = nullptr;
    }
    return *this;
}

template <typename T>
template <typename U>
void BinaryTree<T>::_Create(
    const std::string &s, U &&ref, size_t &index, node *&subtree ) {
    subtree = nullptr;
    if ( index == s.size() || s[index] == ref ) {
        return;
    }
    subtree      = new node();
    subtree->val = s[index++];
    _Create( s, std::forward<U>( ref ), index, subtree->left );
    _Create( s, std::forward<U>( ref ), ++index, subtree->right );
}

template <typename T>
void BinaryTree<T>::_CreateCopy( node *src, node *&dest ) {
    if ( src ) {
        dest      = new node();
        dest->val = src->val;
        _CreateCopy( src->left, dest->left );
        _CreateCopy( src->right, dest->right );
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
    Stack<decltype( root )> stk;
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

template <typename T> size_t BinaryTree<T>::_Depth( node *root ) {
    if ( root == nullptr ) {
        return 0;
    } else {
        return std::max( _Depth( root->left ), _Depth( root->right ) ) + 1;
    }
}

template<typename T>
bool BinaryTree<T>::_isCompleteBinaryTree(node *root) {
    Queue<decltype(root)> q;
    bool flag = false;
    auto cur = root;
    q.push(root);
    while(cur) {
        if(cur->left == nullptr && cur->right) {
            return false;
        }
        if(flag == true && (cur->left || cur->right)) {
            return false;
        }
        if(cur->left) {
            q.push(cur->left);
        }
        if(cur->right) {
            q.push(cur->right);
        }
        q.pop();
        if(q.size()) {
            cur = q.front();
        } else {
            cur = nullptr;
        }
    }
    return true;
}

template<typename T>
void BinaryTree<T>::_CreateWithPostAndMid(std::unordered_map<T , size_t>& pos , const std::vector<T>& post, node*& subtree , size_t il , size_t ir , size_t pl , size_t pr) {
    subtree = new node();
    subtree->val = post[pr];
    auto k = pos[post[pr]];
    if(il < k) _CreateWithPostAndMid(pos , post , subtree->left , il , k - 1 , pl , k - 1 - il + pl);
    if(ir > k) _CreateWithPostAndMid(pos , post , subtree->right , k + 1 , ir , k - 1 - il + pl + 1 , pr - 1);
}
