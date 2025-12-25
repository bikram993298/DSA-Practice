class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        vector<int> deg(n + 1, 0);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u][v] = adj[v][u] = true;
            deg[u]++;
            deg[v]++;
        }

        int ans = INT_MAX;

        // Try all trios
        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                if (!adj[a][b]) continue;
                for (int c = b + 1; c <= n; c++) {
                    if (adj[a][c] && adj[b][c]) {
                        int degree = deg[a] + deg[b] + deg[c] - 6;
                        ans = min(ans, degree);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
