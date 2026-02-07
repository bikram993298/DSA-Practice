class Solution {
public:
    int ans = 1;
    vector<vector<int>> adj;
    string s;

    int dfs(int u) {
        int mx1 = 0, mx2 = 0;

        for (int v : adj[u]) {
            int len = dfs(v);

            if (s[v] == s[u])
                continue;

            if (len > mx1) {
                mx2 = mx1;
                mx1 = len;
            } else if (len > mx2) {
                mx2 = len;
            }
        }

        ans = max(ans, 1 + mx1 + mx2);
        return 1 + mx1;
    }

    int longestPath(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;
        adj.assign(n, {});

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0);
        return ans;
    }
};
