#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph {
    std::vector<std::vector<int>> adj_matrix;

public:
    Graph(int n); // Constructor
    void add_edge(int u, int v);
    void print_adj_matrix();
    const std::vector<int>& get_neighbors(int u) const;
};

#endif // GRAPH_H