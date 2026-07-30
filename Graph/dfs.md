# DFS of Graph (GFG)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)**

---

## 📝 Problem Description

Given a connected undirected graph represented by an adjacency list `adj`, return a list containing the DFS traversal of the graph starting from the 0th vertex from left to right.

---

## 💡 Intuition & Core Logic

Depth-First Search (DFS) is a graph traversal algorithm that explores as deep as possible along each branch before backtracking. 

1. **Visited Array**: Maintain a `visited` boolean array of size `V` (number of vertices) to ensure we don't visit the same node multiple times (avoiding infinite loops).
2. **Recursion/Call Stack**: Use a recursive helper function `dfsHelper`.
3. **Traversal**:
   - Mark the current node as `visited` and append it to the result list `res`.
   - Traverse all unvisited neighbors of the current node recursively.

---

## 🔄 Step-by-Step Dry Run

Consider the following adjacency list representing a connected undirected graph with `V = 5` vertices:
- `adj[0] = {1, 2, 3}`
- `adj[1] = {0}`
- `adj[2] = {0, 4}`
- `adj[3] = {0}`
- `adj[4] = {2}`

Starting DFS from node `0`:

| Step | Call | Visited Nodes | Current Node | Action & Neighbors Visited | Result Array |
|---|---|---|---|---|---|
| 1 | `dfsHelper(0)` | `{0}` | `0` | Visit `0`. Process neighbor `1` (unvisited). | `[0]` |
| 2 | `dfsHelper(1)` | `{0, 1}` | `1` | Visit `1`. Neighbor `0` is already visited. Return. | `[0, 1]` |
| 3 | Back at `0` | `{0, 1}` | `0` | Process next neighbor `2` (unvisited). | `[0, 1]` |
| 4 | `dfsHelper(2)` | `{0, 1, 2}` | `2` | Visit `2`. Neighbor `0` is visited. Process neighbor `4` (unvisited). | `[0, 1, 2]` |
| 5 | `dfsHelper(4)` | `{0, 1, 2, 4}` | `4` | Visit `4`. Neighbor `2` is visited. Return. | `[0, 1, 2, 4]` |
| 6 | Back at `2` | `{0, 1, 2, 4}` | `2` | No more unvisited neighbors. Return. | `[0, 1, 2, 4]` |
| 7 | Back at `0` | `{0, 1, 2, 4}` | `0` | Process next neighbor `3` (unvisited). | `[0, 1, 2, 4]` |
| 8 | `dfsHelper(3)` | `{0, 1, 2, 4, 3}` | `3` | Visit `3`. Neighbor `0` is visited. Return. | `[0, 1, 2, 4, 3]` |
| 9 | Back at `0` | `{0, 1, 2, 4, 3}` | `0` | Traversal complete. Return final result. | `[0, 1, 2, 4, 3]` |

Final Output: `[0, 1, 2, 4, 3]`

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    void dfsHelper(vector<vector<int>>& adj, vector<int>& res,
                   int node, vector<bool>& visited) {

        visited[node] = true;
        res.push_back(node);

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfsHelper(adj, res, neigh, visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> res;

        dfsHelper(adj, res, 0, visited);

        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(V + E)` - Where `V` is the number of vertices and `E` is the number of edges. We visit every vertex once, and for each vertex, we iterate through its adjacency list (which sums up to all edges in the graph).
- **Space Complexity**: `O(V)` - For the recursion stack (depth up to `V` in the worst case) and the `visited` array.
