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