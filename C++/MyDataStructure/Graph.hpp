#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;
template <typename T> class Graph {
using PAIR = pair<T , T>;
public:
    explicit Graph() = default;
    Graph<T>( initializer_list<vector<T>> & , bool , size_t);
    Graph(const Graph&);
    Graph(Graph&&);
    Graph& operator=(const Graph&);
    Graph& operator=(Graph&&);
    ~Graph() { clear(); }
    void clear();
    vector<size_t> GetInDegree();
    vector<size_t> GetOutDegree();
    vector<size_t> GetTotalDegree();
    void print_graph();

private:
    vector<vector<PAIR>> graph;
    size_t TotalNodes;
};


template<typename T>
Graph<T>::Graph(initializer_list<vector<T>> &list , bool st , size_t totalNodes) {
    TotalNodes = totalNodes;
    graph.resize(totalNodes);
    for(auto& i : list) {
        auto u = i[0] , v = i[1] , w = i[2];
        u-- , v--;
        if(st) {
            graph[u].emplace_back(v , w);
        } else {
            graph[u].emplace_back(v , w);
            graph[v].emplace_back(u , w);
        }
    }
}

template<typename T>
Graph<T>::Graph(const Graph& other) {
    graph = other.graph;
    TotalNodes = other.TotalNodes;
}

template<typename T>
Graph<T>::Graph(Graph&& other) {
    graph = std::move(other.graph);
    TotalNodes = other.TotalNodes;
}

template<typename T>
void Graph<T>::clear() {
    graph.clear();
}

template<typename T>
vector<size_t> Graph<T>::GetInDegree() {
    vector<size_t> InDegree;
    for(size_t i = 0; i < TotalNodes; i++) {
        size_t countInDegree = 0;
        for(size_t j = 0; j < TotalNodes; j++) {
            if(i == j) continue;
            for(size_t k = 0; k < graph[j].size(); k++) {
                countInDegree += graph[j][k].first == i;
            }
        }
        InDegree.emplace_back(countInDegree);
    }
    
    return std::move(InDegree);
}

template<typename T>
vector<size_t> Graph<T>::GetOutDegree() {
    vector<size_t> OutDegree;
    for(auto& i : graph) {
        OutDegree.emplace_back(i.size());
    }
    return std::move(OutDegree);
}

template<typename T>
vector<size_t> Graph<T>::GetTotalDegree() {
    auto InDegree = GetInDegree() , OutDegree = GetOutDegree();
    vector<size_t> TotalDegree;
    for(size_t i = 0; i < TotalNodes; i++) {
        TotalDegree.emplace_back(InDegree[i] + OutDegree[i]);
    }
    return std::move(TotalDegree);
}

template<typename T>
Graph<T>& Graph<T>::operator=(const Graph& other) {
    if(this != &other) {
        this->clear();
        this->graph = other.graph;
        this->TotalNodes = other.TotalNodes;
    }
    return *this;
}
template<typename T>
Graph<T>& Graph<T>::operator=(Graph&& other) {
    if(this != &other) {
        this->clear();
        this->graph = std::move(other.graph);
        this->TotalNodes = other.TotalNodes;
    }
    return *this;
}

template<typename T>
void Graph<T>::print_graph() {
    for(int i = 0; i < TotalNodes; i++) {
        std::cout << i + 1 << ": ";
        for(const auto& j : graph[i]) {
            std::cout << j.first + 1 << " ";
        }
        std::cout << "\n";
    }
}


