#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <queue>

using namespace std;
template <typename T> class Graph {
    using PAIR = pair<T, T>;

public:
    // 默认无参构造函数
    explicit Graph() = default;
    // @brief: 构造函数
    // @param: initializer_list 给定的边
    // @param: bool 判断是否为无向图
    // @oaram: size_t 点的总个数
    Graph<T>( initializer_list<vector<T>> &, bool, size_t );
    // 复制构造函数
    Graph( const Graph & );
    // 移动构造函数
    Graph( Graph && );
    // 赋值运算符
    Graph &operator=( const Graph & );
    // 移动运算符
    Graph &operator=( Graph && );
    ~Graph() { clear(); }
    // @brief: 清空图
    void clear();
    // @brief: 得到各点的入度数量
    // @return: vector<size_t>
    vector<size_t> GetInDegree();
    // @brief: 得到各点的出度数量
    // @return: vector<size_t>
    vector<size_t> GetOutDegree();
    // @brief: 得到各点的度数量
    // @return: vector<size_t>
    vector<size_t> GetTotalDegree();
    // @brief: 打印图
    void print_graph();
    // @brief: 求图的dfs序列
    vector<size_t> getDFS();
    // @brief: 求图的bfs序列
    tuple<vector<size_t> , size_t> getBFS();

private:
    vector<vector<PAIR>> graph;
    size_t TotalNodes;
    bool isDirectional;
    void _getDFS(const size_t , vector<size_t>& , vector<bool>&);
};

template <typename T>
Graph<T>::Graph(
    initializer_list<vector<T>> &list, bool st, size_t totalNodes ) {
    TotalNodes    = totalNodes;
    isDirectional = st;
    graph.resize( totalNodes );
    for ( auto &i : list ) {
        auto u = i[0], v = i[1], w = i[2];
        u--, v--;
        if ( st ) {
            graph[u].emplace_back( v, w );
        } else {
            graph[u].emplace_back( v, w );
            graph[v].emplace_back( u, w );
        }
    }
}

template <typename T> Graph<T>::Graph( const Graph &other ) {
    graph      = other.graph;
    TotalNodes = other.TotalNodes;
}

template <typename T> Graph<T>::Graph( Graph &&other ) {
    graph      = move( other.graph );
    TotalNodes = move( other.TotalNodes );
}

template <typename T> void Graph<T>::clear() { graph.clear(); }

template <typename T> vector<size_t> Graph<T>::GetInDegree() {
    vector<size_t> InDegree;
    if ( isDirectional ) {
        for ( size_t i = 0; i < TotalNodes; i++ ) {
            size_t countInDegree = 0;
            for ( size_t j = 0; j < TotalNodes; j++ ) {
                if ( i == j ) continue;
                for ( size_t k = 0; k < graph[j].size(); k++ ) {
                    countInDegree += graph[j][k].first == i;
                }
            }
            InDegree.emplace_back( countInDegree );
        }
        // 防止拷贝
        return std::move( InDegree );
    } else {
        return GetOutDegree();
    }
}

template <typename T> vector<size_t> Graph<T>::GetOutDegree() {
    vector<size_t> OutDegree;
    for ( auto &i : graph ) {
        OutDegree.emplace_back( i.size() );
    }
    return std::move( OutDegree );
}

template <typename T> vector<size_t> Graph<T>::GetTotalDegree() {
    vector<size_t> totalDegree;
    if ( isDirectional ) {
        auto OutDegree = GetOutDegree(), InDegree = GetInDegree();
        for ( int i = 0; i < TotalNodes; i++ ) {
            totalDegree.emplace_back( OutDegree[i] + InDegree[i] );
        }
    } else {
        auto OutDegree = GetOutDegree();
        for ( int i = 0; i < TotalNodes; i++ ) {
            totalDegree.emplace_back( OutDegree[i] * 2 );
        }
    }
    return std::move( totalDegree );
}

template <typename T> Graph<T> &Graph<T>::operator=( const Graph &other ) {
    if ( this != &other ) {
        this->clear();
        this->graph      = other.graph;
        this->TotalNodes = other.TotalNodes;
    }
    return *this;
}
template <typename T> Graph<T> &Graph<T>::operator=( Graph &&other ) {
    if ( this != &other ) {
        this->clear();
        this->graph      = move( other.graph );
        this->TotalNodes = move( other.TotalNodes );
    }
    return *this;
}

template <typename T> void Graph<T>::print_graph() {
    for ( int i = 0; i < TotalNodes; i++ ) {
        std::cout << i + 1 << ": ";
        for ( const auto &j : graph[i] ) {
            std::cout << j.first + 1 << " ";
        }
        std::cout << "\n";
    }
}

template<typename T>
tuple<vector<size_t> , size_t> Graph<T>::getBFS() {
    queue<PAIR> q;
    vector<size_t> order , dist(TotalNodes , 0x3f3f3f3f);
    vector<bool> vis(TotalNodes);
    dist[0] = 0;
    std::cout << "TotalNodes is: " << TotalNodes << "\n";
    if(TotalNodes) {
        q.emplace(0 , 0);
        order.emplace_back(0);
        while(!q.empty()) {
            auto [distance , node] = q.front();
            q.pop();
            if(vis[node]) {
                order.emplace_back(node);
            }
            std::cout << "The node is: " << node + 1 <<" The dist of node is: " << dist[node] << "\n";
            vis[node] = false;
            for(auto& [nextNode , nextDistance] : graph[node]) {
                if(dist[nextNode] > dist[node] + nextDistance) {
                    dist[nextNode] = dist[node] + nextDistance;
                    if(!vis[nextNode]) {
                        vis[nextNode] = true;
                        q.emplace(dist[nextNode] , nextNode);
                    }
                }
            }
        }
    }
    return std::move(tuple<vector<size_t> , size_t>(order , dist[TotalNodes - 1]));
}

template<typename T>
vector<size_t> Graph<T>::getDFS() {
    vector<size_t> order;
    vector<bool> vis(TotalNodes);
    _getDFS(0 , order , vis);
    return std::move(order);
}

template<typename T>
void Graph<T>::_getDFS(const size_t node , vector<size_t>& order , vector<bool>& vis) {
    vis[node] = true;
    order.emplace_back(node);
    for(const auto& nextNode : graph[node]) {
        if(!vis[nextNode.first]) {
            _getDFS(nextNode.first, order , vis);
        }
    }
}
