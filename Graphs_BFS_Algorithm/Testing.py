import networkx as nx

G = nx.Graph()

edges = [(0, 1), (0, 2), (1, 3), (1, 4)]
G.add_edges_from(edges)

print("\nBFS starting from vertex 0:")
bfs_edges = list(nx.bfs_edges(G, source=0))
bfs_nodes = [0] + [v for u, v in bfs_edges]
print("BFS Order:", bfs_nodes)

print("\nDFS starting from vertex 0:")
dfs_edges = list(nx.dfs_edges(G, source=0))
dfs_nodes = [0] + [v for u, v in dfs_edges]
print("DFS Order:", dfs_nodes)