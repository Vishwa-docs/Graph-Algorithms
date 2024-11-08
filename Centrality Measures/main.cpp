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

    ////////////////////////////

    // n^2
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
    // n^3
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

    // n^3 -> n^2
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

    // Approx O(k.|E|) {Iterations x Edges}
    vector<double> eigenvector_centrality(double tolerance = 1e-6, int max_iterations = 100)
    {
        // tolerance - Threshold of Convergence, if change in centrality values is less than that it will stop
        // max iter - in case of no convergence, then stop
        int n = adj_matrix.size();
        vector<double> centrality(n, 1.0); // Start with Uniform
        vector<double> new_centrality(n);

        for (int iter = 0; iter < max_iterations; iter++) {
            double norm_factor = 0.0;

            // New centralities
            for (int i = 0; i < n; ++i) {
                new_centrality[i] = 0.0;
                for (int j = 0; j < n; ++j) {
                    new_centrality[i] += adj_matrix[i][j] * centrality[j];
                }
                norm_factor += new_centrality[i] * new_centrality[i]; // normalization
            }

            norm_factor = sqrt(norm_factor); // Normalization Factor

            if (norm_factor > 0) {
                for (int i = 0; i < n; ++i) {
                    new_centrality[i] /= norm_factor;
                }
            }

            // Check convergence
            double max_diff = 0.0;
            for (int i = 0; i < n; ++i) {
                max_diff = max(max_diff, fabs(new_centrality[i] - centrality[i]));
            }

            centrality.swap(new_centrality);

            if (max_diff < tolerance) break; // converged
        }

        return centrality;
    }

    ///////////////////////////

    // n^3 (Floyd part)
    vector<double> harmonic_centrality()
    {
        vector<vector<int>> dist = floyd_warshall();
        int n = adj_matrix.size();
        vector<double> harmonic(n, 0.0);

        // n^2
        for (int i = 0; i < n; ++i) {
            double sum_inverse_distances = 0.0;

            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > 0 && dist[i][j] != numeric_limits<int>::max()) { // Only reachable nodes
                    sum_inverse_distances += static_cast<double>(1) / dist[i][j]; // If yes, add inverse distance
                }
            }

            harmonic[i] = sum_inverse_distances;
        }

        return harmonic;
    }
};

void print_degree_centrality(Graph g) {
    vector<int> degrees = g.degree_centrality();
    cout << "Degree Centrality of the nodes: ";
    for (int degree : degrees) {
        cout << degree << " ";
    }
    cout << endl;
}

void print_closeness_centrality(Graph g) {
    vector<double> closeness = g.closeness_centrality();
    cout << "Closeness Centrality of the nodes: ";
    for (double centrality : closeness) {
        cout << centrality << " ";
    }
    cout << endl;
}

void print_eigenvector_centrality(Graph g) {
    vector<double> eigenvector_centralities = g.eigenvector_centrality();
    cout << "Eigenvector Centrality of the nodes: ";
    for (double centrality : eigenvector_centralities) {
        cout << centrality << " ";
    }
    cout << endl;
}

void print_harmonic_centrality(Graph g) {
    vector<double> harmonic_centralities = g.harmonic_centrality();
    cout << "Harmonic Centrality of the nodes: ";
    for (double centrality : harmonic_centralities) {
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
    print_eigenvector_centrality(g);
    print_harmonic_centrality(g);

    return 0;
}