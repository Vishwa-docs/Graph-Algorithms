#include "Graph.h"

Graph::Graph(int n) {
    adj_matrix = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
}

void Graph::add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

void Graph::print_adj_matrix() {
    std::cout << "Adjacency Matrix for the Graph: " << std::endl;
    int n = adj_matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

const std::vector<int>& Graph::get_neighbors(int u) const {
    return adj_matrix[u];
}