# 🕸️ Graph Pattern

Graphs consist of nodes (vertices) and connections (edges) between them. Graph traversal algorithms are fundamental to solving connectivity, pathfinding, and cycle-detection problems. 

---

## 📝 Concept Cheatsheet

### Depth-First Search (DFS) Template
DFS explores as deep as possible along each branch before backtracking. It is typically implemented recursively (using the system call stack) or iteratively (using an explicit stack).

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    // Process the node (e.g., store in result, check condition)
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **DFS of Graph** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1) | [`dfs.cpp`](./dfs.cpp) | [Explanation & Dry Run](dfs.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
