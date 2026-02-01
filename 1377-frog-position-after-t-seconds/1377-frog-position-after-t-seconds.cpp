class Solution {
public:
    vector<vector<int>> adj;
    double ans = 0.0;
    int target, T;

    void dfs(int node, int parent, int time, double prob) {
        // If time exceeded
        if (time > T) return;

        // Count unvisited neighbors
        int children = 0;
        for (int nei : adj[node]) {
            if (nei != parent) children++;
        }

        // If time is exactly T
        if (time == T) {
            if (node == target) ans = prob;
            return;
        }

        // If frog is stuck (no unvisited neighbors)
        if (children == 0) {
            if (node == target) ans = prob;
            return;
        }

        // Distribute probability
        for (int nei : adj[node]) {
            if (nei == parent) continue;
            dfs(nei, node, time + 1, prob / children);
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target_) {
        target = target_;
        T = t;

        adj.resize(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0, 0, 1.0);
        return ans;
    }
};
