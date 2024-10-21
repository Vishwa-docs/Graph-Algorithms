#include <iostream>
#include "Graph.h"
#include "Search.h"

int main() {
    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);

    g.print_adj_matrix();

    std::cout << "BFS starting from vertex 0: ";
    BFS(g, 0);

    std::cout << "DFS starting from vertex 0: ";
    DFS(g, 0);

    return 0;
}