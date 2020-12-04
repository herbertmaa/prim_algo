#include <iostream>
#include <set>
#include "Graph.hpp"
#include "Compator.hpp"
#include <queue>

/*
 * In computer science, Prim's algorithm is a greedy algorithm that finds a minimum
 * spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that
 * includes every vertex, where the total weight of all the edges in the tree is minimized. The algorithm operates
 * by building this tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest
 * possible connection from the tree to another vertex.
 */
void prim(Graph &graph);

Graph* test_graph9();
Graph* test_graph4();

// MST is a subgraph of an undirected weighted graph
// such that it is acyclic
// includes all vertices
// the total cost associated with edges is the minimum among all possible spanning trees
// mst may not be unique

//represent a,b,c,d as 0,1,2,3
int main() {

    Graph* g1 = test_graph4();
    Graph* g2 = test_graph9();
//    prim(*g1);
    prim(*g2);
    delete g2;
    delete g1;
}

void prim(Graph &graph) {

    Graph result(graph.num_vertices); // our result will contain all vertices from the original graph.
    int num_edges = graph.num_vertices-1; // our result will contain vertices -1 edges
    std::set<int> sets_in_mst; // a set that keeps track of vertices already included in MST
    sets_in_mst.insert(0);
    for (int i = 0; i < num_edges; ++i) {
        pair<int, int> *min_pair = nullptr;
        int origin = -1;
        // more efficient way of doing this would be to have a min heap
        for(int j = 0; j < graph.num_vertices; ++j){
            if(sets_in_mst.find(j) == sets_in_mst.end()) continue;
            for (auto& edge: graph.adj_list[j]) {
                if(sets_in_mst.find(edge.first) == sets_in_mst.end() && (min_pair == nullptr || edge.second < min_pair->second)) {
                    min_pair = &edge;
                    origin = j;
                }
            }
        }

        if(min_pair != nullptr){
            sets_in_mst.insert(min_pair->first);
            cout << origin << "->" <<min_pair->first << endl;
            result.addEdge(origin, min_pair->first, min_pair->second);
        }


    }


    result.printGraph();

}

Graph* test_graph4(){
    Graph* g = new Graph(4);

    g->addEdge(0, 1, 1); //a -> b  b <- a weight of 1
    g->addEdge(0, 3, 4); //a -> d  d <- a weight of 4
    g->addEdge(0, 2, 1); //a -> c  c <- a weight of 1

    g->addEdge(1, 2, 3); //b -> c  c <- b weight of 3

    g->addEdge(2, 3, 2); //c -> d  d <- c weight of 2
    return g;
}

Graph* test_graph9(){
    Graph* g = new Graph(9);

    g->addEdge(0, 1, 4); //a -> b  b <- a weight of 4
    g->addEdge(0, 7, 9); //a -> h  h <- a weight of 9

    g->addEdge(1, 2, 8); //b -> c  c <- b weight of 8
    g->addEdge(1, 7, 11); //b -> h  h <- b weight of 11

    g->addEdge(2, 3, 7); //c -> d  d <- c weight of 7
    g->addEdge(2, 5, 4); //c -> f  f <- c weight of 4
    g->addEdge(2, 8, 2); //c -> i  i <- c weight of 2

    g->addEdge(3, 4, 9); //d -> e  e <- d weight of 9
    g->addEdge(3, 5, 14); //d -> f  f <- d weight of 14

    g->addEdge(4, 5, 10); //e -> f  f <- e weight of 10

    g->addEdge(5, 6, 2); //f -> g  g <- f weight of 2

    g->addEdge(6, 7, 1); //g -> h  g <- h weight of 1
    g->addEdge(6, 8, 6); //g -> i  g <- i weight of 6

    g->addEdge(7, 8, 7); //h -> i  h <- i weight of 7

    return g;
}