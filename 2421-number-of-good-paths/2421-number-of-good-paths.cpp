class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // value -> list of nodes
        map<int, vector<int>> nodesByValue;
        for (int i = 0; i < n; i++)
            nodesByValue[vals[i]].push_back(i);

        vector<bool> active(n, false);
        int ans = n; // each node alone

        for (auto &[value, nodes] : nodesByValue) {
            // activate nodes
            for (int u : nodes) {
                active[u] = true;
                for (int v : adj[u]) {
                    if (active[v]) {
                        unite(u, v);
                    }
                }
            }

            // count nodes with this value per component
            unordered_map<int, int> count;
            for (int u : nodes) {
                count[find(u)]++;
            }

            for (auto &[root, k] : count) {
                ans += k * (k - 1) / 2;
            }
        }

        return ans;
    }
};
