#include <iostream>
#include <set>
#include "Graph.hpp"
#include <limits>

/*
 * In computer science, Prim's algorithm is a greedy algorithm that finds a minimum
 * spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that
 * includes every vertex, where the total weight of all the edges in the tree is minimized. The algorithm operates
 * by building this tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest
 * possible connection from the tree to another vertex.
 */
void prim(Graph &graph);

// MST is a subgraph of an undirected weighted graph
// such that it is acyclic
// includes all vertices
// the total cost associated with edges is the minimum among all possible spanning trees
// mst may not be unique

//represent a,b,c,d as 0,1,2,3
int main() {
    Graph g(4);

    g.addEdge(0, 1, 1); //a -> b  b <- a weight of 1
    g.addEdge(0, 3, 4); //a -> d  d <- a weight of 4
    g.addEdge(0, 2, 1); //a -> c  c <- a weight of 1

    g.addEdge(1, 2, 3); //b -> c  c <- b weight of 3

    g.addEdge(2, 3, 2); //c -> d  d <- c weight of 2

//    g.printGraph();
    prim(g);
}

void prim(Graph &graph) {

    Graph result(4); // our result will contain all vertices from the original graph.
    std::set<int> sets_in_mst; // a set that keeps track of vertices already included in MST

    for (int i = 0; i < graph.num_vertices; ++i) {
        pair<int, int> *min_pair = nullptr;
        for (auto& edge: graph.adj_list[i]) {
            if (sets_in_mst.find(edge.first) != sets_in_mst.end()) continue;
            if (min_pair == nullptr || edge.second < min_pair->second) {
                min_pair = &edge;
            }
        }
        if(min_pair != nullptr){
            sets_in_mst.insert(min_pair->first);
            result.addEdge(i, min_pair->first, min_pair->second);
        }
    }
    result.printGraph();

}