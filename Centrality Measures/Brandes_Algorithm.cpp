#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath> // For std::sqrt

using namespace std;

class Graph {
    vector<vector<int>> adj_matrix;

public:
    Graph(int n) // n vertices
    {
        adj_matrix = vector<vector<int>>(n, vector<int>(n, 0)); // Filled with 0s
    }

    // Add both edges, considering undirected graph
    void add_edge(int u, int v)
    {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    void print_adj_matrix()
    {
        cout << "Adjacency Matrix for the Graph: " << endl;
        int n = adj_matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Betweenness Centrality using Brandes' Algorithm
    vector<double> betweenness_centrality()
    {
        int n = adj_matrix.size();
        vector<double> betweenness(n, 0.0);

        for (int s = 0; s < n; s++) {
            vector<int> sigma(n, 0); // Number of shortest paths
            vector<double> delta(n, 0.0); // Dependency of nodes
            vector<vector<int>> pred(n); // Predecessors in the shortest path

            sigma[s] = 1; // There is one shortest path from s to s

            // BFS initialization
            queue<int> Q;
            vector<int> dist(n, -1);
            Q.push(s);
            dist[s] = 0;

            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();

                for (int w = 0; w < n; w++) {
                    if (adj_matrix[v][w] == 1) { // If there's an edge
                        if (dist[w] < 0) { // w is not visited
                            dist[w] = dist[v] + 1;
                            Q.push(w);
                        }
                        // If this path is the shortest one to w
                        if (dist[w] == dist[v] + 1) {
                            sigma[w] += sigma[v]; // Increment number of paths to w
                            pred[w].push_back(v); // Add v as a predecessor of w
                        }
                    }
                }
            }

            // Accumulate dependencies
            vector<double> dependency(n, 0.0);
            while (!Q.empty()) Q.pop(); // Clear queue for next use

            for (int w = n - 1; w >= 0; w--) {
                for (int v : pred[w]) {
                    dependency[v] += (static_cast<double>(sigma[v]) / sigma[w]) * (1 + dependency[w]);
                }
                if (w != s) { // Don't accumulate dependency for source node
                    betweenness[w] += dependency[w];
                }
            }
        }

        return betweenness;
    }
};

void print_betweenness_centrality(Graph g) {
    vector<double> betweenness = g.betweenness_centrality();
    cout << "Betweenness Centrality of the nodes: ";
    for (double centrality : betweenness) {
        cout << centrality << " ";
    }
    cout << endl;
}

int main()
{
    int n = 6; // No of Vertices
    Graph g(n); // Create Graph

    // Add Edges
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(2, 5);
    g.add_edge(3, 5);
    g.add_edge(4, 2);

    g.print_adj_matrix();

    print_betweenness_centrality(g);

    return 0;
}