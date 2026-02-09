class Solution {
public:
    vector<vector<pair<int,int>>> g;
    vector<int> ans;

    int dfs1(int u, int p) {
        int c = 0;
        for (auto [v, cost] : g[u]) {
            if (v == p) continue;
            c += cost + dfs1(v, u);
        }
        return c;
    }

    void dfs2(int u, int p) {
        for (auto [v, cost] : g[u]) {
            if (v == p) continue;
           
            ans[v] = ans[u] + (cost == 0 ? 1 : -1);
             dfs2(v, u);
            
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        g.assign(n, {});
        ans.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back({v, 0});
            g[v].push_back({u, 1}); // reverse needed
        }

        ans[0] = dfs1(0, -1);  
        dfs2(0, -1);

        return ans;
    }
};
