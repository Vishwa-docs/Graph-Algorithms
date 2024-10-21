import networkx as nx
import numpy as np
import matplotlib.pyplot as plt



adj_matrix = np.array([[0, 1, 0, 1, 1, 0],
                       [1, 0, 1, 0, 0, 0],
                       [0, 1, 0, 0, 1, 1],
                       [1, 0, 0, 0, 0, 1],
                       [1, 0, 1, 0, 0, 0],
                       [0, 0, 1, 1, 0, 0]])

# Create the graph from adjacency matrix
G = nx.from_numpy_array(adj_matrix)

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True)
plt.show()


closeness_centrality = nx.closeness_centrality(G)
betweeness_centrality = nx.betweenness_centrality(G)

# Print the results
print("Closeness Centrality:", closeness_centrality)
print("Betweenness Centrality:", betweeness_centrality)