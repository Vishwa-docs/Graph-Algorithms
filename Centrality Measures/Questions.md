# What is DP
Solve complex problems by breaking them down into simpler subproblems. 
It is particularly effective for optimization problems where the solution can be expressed recursively

# Floyd Warshall Algorithm
+ All-pairs shortest path
+ It follows Dynamic Programming approach to check every possible path going via every possible node in order to calculate shortest distance between every pair of nodes.

## Working
+ Initialize distance matrix (Adj for unweighted)
+ Treat every vertex (k) as the intermediate node
+ Then, for every pair of vertices (i, j) use k and intermediate and do calc

+ Does not work for negative cycles

## Analysis
+ n^3 and n^2 aux space

## Sparse Graphs
This is better for Dense, Johnsons is better for sparse

## How it follows DP
1. Overlapping Subproblems : Smaller and smaller problems
2. Optimal Substructure : Optimal solution can be found from subproblems


# Bellman Ford
+ Single Source Shortest Path

## How it Works?
+ Start from A, that is 0. Rest all dist in inf
+ Start relaxing edges 
  + Current Distance of B > (Distance of A) + (Weight of A to B) i.e. Infinity > 0 + 5
  + Hence, relax it
+ Continue for N-1 times, in each step go for the adjacent nodes to current node

## How it handles Negative Cycles?
+ If you do one more relaxation, Nth time, and there is some cycle that changes value, then there is -ve cycle

## Time Complex
+ O(V*E)