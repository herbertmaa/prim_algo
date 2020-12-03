//
// Created by Herbert Ma on 2020-12-03.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int num_vertices = 0;
    vector<vector<pair<int, int>>> adj_list;

    Graph(int v) : num_vertices(v) {
        adj_list.reserve(num_vertices);
    };

    void addEdge(int src, int dest, int weight);

    void printGraph() const;

    inline int getSize() const{ return num_vertices; };

};