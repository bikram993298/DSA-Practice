class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> val(n), dp1(n), ans(n);
        for(int i = 0; i < n; i++)
            val[i] = good[i] == 1 ? 1 : -1;

        function<void(int,int)> dfs1 = [&](int u, int p) {
            dp1[u] = val[u];
            for (int v : g[u]) {
                if (v == p) continue;
                dfs1(v, u);
                dp1[u] += max(0, dp1[v]);
            }
        };

        dfs1(0, -1);

        function<void(int,int,int)> dfs2 = [&](int u, int p, int acc) {
            ans[u] = dp1[u] + max(0, acc);
            for (int v : g[u]) {
                if (v == p) continue;
                int fromParent = ans[u] - max(0, dp1[v]);
                dfs2(v, u, fromParent);
            }
        };

        dfs2(0, -1, 0);   // ← You forgot this call

        return ans;       // ← You also forgot this line
    }
};
