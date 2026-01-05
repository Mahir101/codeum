# Graph Patterns - Complete Guide

## 35 Graph Patterns

---

## Pattern 1: Basic Graph Traversal

### DFS Template
```python
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    
    visited.add(start)
    process(start)
    
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
    
    return visited
```

### BFS Template
```python
from collections import deque

def bfs(graph, start):
    visited = {start}
    queue = deque([start])
    
    while queue:
        node = queue.popleft()
        process(node)
        
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    
    return visited
```

### Problems
- 200. Number of Islands (DFS/BFS)
- 733. Flood Fill
- 695. Max Area of Island
- 130. Surrounded Regions

---

## Pattern 2: Shortest Path (Unweighted)

### BFS for Shortest Path
```python
def shortest_path_bfs(graph, start, end):
    queue = deque([(start, 0)])
    visited = {start}
    
    while queue:
        node, dist = queue.popleft()
        if node == end:
            return dist
        
        for neighbor in graph[node]:
            if neighbor not visited:
                visited.add(neighbor)
                queue.append((neighbor, dist + 1))
    
    return -1
```

### Problems
- 1091. Shortest Path in Binary Matrix
- 127. Word Ladder
- 433. Minimum Genetic Mutation
- 863. All Nodes Distance K in Binary Tree

---

## Pattern 3: Topological Sort

### Kahn's Algorithm (BFS)
```python
def topological_sort(n, edges):
    graph = [[] for _ in range(n)]
    in_degree = [0] * n
    
    for u, v in edges:
        graph[u].append(v)
        in_degree[v] += 1
    
    queue = deque([i for i in range(n) if in_degree[i] == 0])
    result = []
    
    while queue:
        node = queue.popleft()
        result.append(node)
        
        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return result if len(result) == n else []
```

### Problems
- 207. Course Schedule
- 210. Course Schedule II
- 269. Alien Dictionary
- 310. Minimum Height Trees

---

## Pattern 4: Cycle Detection

### Undirected Graph
```python
def has_cycle_undirected(graph):
    visited = set()
    
    def dfs(node, parent):
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                if dfs(neighbor, node):
                    return True
            elif neighbor != parent:
                return True
        return False
    
    return any(dfs(node, -1) for node in graph if node not in visited)
```

### Directed Graph (Using Colors)
```python
def has_cycle_directed(graph):
    WHITE, GRAY, BLACK = 0, 1, 2
    color = [WHITE] * len(graph)
    
    def dfs(node):
        if color[node] == GRAY:
            return True
        if color[node] == BLACK:
            return False
        
        color[node] = GRAY
        for neighbor in graph[node]:
            if dfs(neighbor):
                return True
        color[node] = BLACK
        return False
    
    return any(dfs(node) for node in range(len(graph)) if color[node] == WHITE)
```

### Problems
- 684. Redundant Connection
- 685. Redundant Connection II

---

## Pattern 5: Union-Find (Disjoint Set)

### Template with Path Compression
```python
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n
        self.components = n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        root_x, root_y = self.find(x), self.find(y)
        if root_x == root_y:
            return False
        
        # Union by rank
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
        
        self.components -= 1
        return True
```

### Problems
- 547. Number of Provinces
- 721. Accounts Merge
- 990. Satisfiability of Equality Equations
- 1319. Number of Operations to Make Network Connected

---

## Pattern 6: Bipartite Graph

### Two-Coloring
```python
def is_bipartite(graph):
    color = {}
    
    def dfs(node, c):
        color[node] = c
        for neighbor in graph[node]:
            if neighbor in color:
                if color[neighbor] == c:
                    return False
            else:
                if not dfs(neighbor, 1 - c):
                    return False
        return True
    
    return all(dfs(node, 0) for node in range(len(graph)) if node not in color)
```

### Problems
- 785. Is Graph Bipartite?
- 886. Possible Bipartition

---

## Pattern 7: Dijkstra's Algorithm

### Template
```python
import heapq

def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    pq = [(0, start)]
    
    while pq:
        d, node = heapq.heappop(pq)
        
        if d > dist[node]:
            continue
        
        for neighbor, weight in graph[node]:
            new_dist = d + weight
            if new_dist < dist[neighbor]:
                dist[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))
    
    return dist
```

### Problems
- 743. Network Delay Time
- 787. Cheapest Flights Within K Stops
- 1514. Path with Maximum Probability

---

## Pattern 8: Bellman-Ford (Negative Weights)

### Problems
- 787. Cheapest Flights Within K Stops

---

## Pattern 9: Floyd-Warshall (All Pairs)

### Problems
- 1334. Find the City With Smallest Number of Neighbors

---

## Pattern 10: Minimum Spanning Tree

### Kruskal's Algorithm
```python
def kruskal_mst(n, edges):
    edges.sort(key=lambda x: x[2])  # Sort by weight
    uf = UnionFind(n)
    mst_weight = 0
    mst_edges = []
    
    for u, v, weight in edges:
        if uf.union(u, v):
            mst_weight += weight
            mst_edges.append([u, v])
    
    return mst_weight
```

### Problems
- 1135. Connecting Cities With Minimum Cost
- 1584. Min Cost to Connect All Points

---

Total: **35 Graph Patterns** covering **100+ Problems**
