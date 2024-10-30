# Graph Centralities
+ [Source](https://www.turing.com/kb/graph-centrality-measures)


> **Centrality** deals with distinguishing important nodes in a graph. 
> We can define different factors to consider these as important.


## Degree Centrality
+ For an undirected graph, the degree centrality of the graph is the node with the maximum degree (That is, the number of edges connecting to the node)
+ This is useful for finding highly connected individuals, which can help to quicly connect to a wider network.

## Closeness Centrality
> the reciprocal of the sum of the shortest path distances from to all other nodes in the graph.
+ The average shortest distance between a vertex and all other vertices in the network. It's calculated by dividing the sum of all the shortest paths by the total number of nodes minus one.
+ Identifies how close a node is to all other nodes in the graph.
+ Also known as GD, which is the number of links included in the shortest path between two nodes.
+ Closeness Centrality finds those individuals who can influence the network in the fastest way.

## Betweenness Centrality
+ Measures the number of times a node appears in the shortest path between any two nodes
+ These nodes are usually the most influencial in a bipartite graph.

## Eigenvector Centrality and PageRank
+ Measures the Node's importance as a function of its neighbours
+ Google's Pagerank is a variation, which Google uses to Rank webpages usign a Random Walk Approach
- Connections Matter: A node connected to many other important nodes will have a higher Eigenvector Centrality score
- Transitive Influence: The importance of a node is amplified by the importance of the nodes it's connected to.

### Drawback
- Sensitive to Network Structure
- Doesn't account for directionality

### Mathematics
Ax = λx

## Harmonic Centrality
+ Sum of the reciprocals of the shortest distances from x to all other vertices
+ If there is no edge, consider infinite, and hence reciprocal is 0 (Hence better than closeness)
+ A higher harmonic centrality score indicates that a vertex is either directly connected to many other vertices or is close to many vertices within the graph

## Others
+ Katz Centrality
+ Percolation Centrality