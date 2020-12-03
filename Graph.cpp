//
// Created by Herbert Ma on 2020-12-03.
//

#include "Graph.hpp"


/* Makes a directed graph from src -> dest and dest -> src */
void Graph::addEdge(int src, int dest, int weight) {
    adj_list[src].push_back(make_pair(dest, weight));
    adj_list[dest].push_back(make_pair(src, weight));
}

void Graph::printGraph() const {
    int v, w;
    for (int u = 0; u < num_vertices; u++) //iterate through the number of vertices
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto & it : adj_list[u]) // iterate through the pairs
        {
            v = it.first;
            w = it.second;
            cout << "\tNode " << v << " with edge weight = "
                 << w << "\n";
        }
        cout << "\n";
    }
}
