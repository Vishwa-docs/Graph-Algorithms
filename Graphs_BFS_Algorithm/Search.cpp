#include "Search.h"
#include <queue>
#include <stack>
#include <unordered_set>

void BFS(const Graph& graph, int start) {
    std::queue<int> q;
    std::unordered_set<int> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        const auto& neighbors = graph.get_neighbors(node);
        for (size_t i = 0; i < neighbors.size(); ++i) {
            if (neighbors[i] == 1 && visited.find(i) == visited.end()) {
                q.push(i);
                visited.insert(i);
            }
        }
    }
    std::cout << std::endl;
}

void DFS(const Graph& graph, int start) {
    std::stack<int> s;
    std::unordered_set<int> visited;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            std::cout << node << " ";

            const auto& neighbors = graph.get_neighbors(node);
            for (size_t i = 0; i < neighbors.size(); ++i) {
                if (neighbors[i] == 1 && visited.find(i) == visited.end()) {
                    s.push(i);
                }
            }
        }
    }
    std::cout << std::endl;
}