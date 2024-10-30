#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Graph {
    vector<vector<int>> adj_matrix;

public:
    Graph(int n) // n vertices
    {
        adj_matrix = vector<vector<int>> (n, vector<int>(n, 0)); // Filled with 0s
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

    ////////////////////////////

    vector<int> degree_centrality()
    {
        int n = adj_matrix.size();
        vector<int> degrees(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj_matrix[i][j] == 1) {
                    degrees[i]++; // If there is an edge, increment (Rowwise)
                }
            }
        }

        return degrees;
    }

    ////////////////////

    // Floyd-Warshall algo - All pairs Shortest path
    vector<vector<int>> floyd_warshall()
    {
        int n = adj_matrix.size();
        vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));

        // Find distance matrix from adjacency matrix (Its the same)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj_matrix[i][j] == 1) {
                    dist[i][j] = 1;
                }
            }
            dist[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != numeric_limits<int>::max() && dist[k][j] != numeric_limits<int>::max()) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return dist;
    }

    vector<double> closeness_centrality()
    {
        vector<vector<int>> dist = floyd_warshall();
        int n = adj_matrix.size();
        vector<double> closeness(n, 0.0);

        for (int i = 0; i < n; i++) { // Iterates through each vertex i
            double sum = 0.0;

            // Sums the distances from vertex i to all other vertices j, ignoring unreachable vertices and itself.
            for (int j = 0; j < n; j++) {
                if (dist[i][j] < numeric_limits<int>::max() && i != j) {
                    sum += dist[i][j];
                }
            }
            if (sum > 0) {
                closeness[i] = (n - 1) / sum; // Closeness centrality is the reciprocal of the average distance to other vertices.
            } else {
                closeness[i] = 0; // If no connections, centrality is 0
            }
        }

        return closeness;
    }

    ///////////////////////////
};

void print_degree_centrality(Graph i) {
    vector<int> degrees = i.degree_centrality();
    cout << "Degree Centrality of the nodes: ";
    for (int degree : degrees) {
        cout << degree << " ";
    }
    cout << endl;
}

void print_closeness_centrality(Graph i) {
    vector<double> closeness = i.closeness_centrality();
    cout << "Closeness Centrality of the nodes: ";
    for (double centrality : closeness) {
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

    print_degree_centrality(g);
    print_closeness_centrality(g);

    return 0;
}