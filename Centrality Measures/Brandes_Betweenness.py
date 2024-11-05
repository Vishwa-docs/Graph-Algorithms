import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

edges = [(0, 1), (0, 3), (0, 4), (1, 2), (2, 5), (3, 5), (4, 2)]
G.add_edges_from(edges)

adj_matrix = nx.to_numpy_array(G)
print("Adjacency Matrix for the Graph:")
print(adj_matrix)

betweenness = nx.betweenness_centrality(G)

print("Betweenness Centrality of the nodes:")
for node, centrality in betweenness.items():
    print(f"Node {node}: {centrality}")