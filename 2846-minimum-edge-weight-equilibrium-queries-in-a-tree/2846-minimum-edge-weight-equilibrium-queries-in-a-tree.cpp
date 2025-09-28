class Solution {
public:
    const int MAX = 20; // log2(1e5) ~ 17, so 20 is safe
    const int W = 26;   // weights range [1..26]

    int n;
    vector<vector<int>> table; // binary lifting table
    vector<int> depth;
    vector<vector<int>> cnt;   // cnt[u][w] = #edges with weight w from root to u
    vector<vector<pair<int,int>>> adj; // adjacency: (neighbor, weight)

    // dfs to compute depth, parent, and counts
    void dfs(int u, int p, int w) {
        if (p != -1) {
            depth[u] = depth[p] + 1;
            for (int x = 1; x <= W; x++) cnt[u][x] = cnt[p][x];
            cnt[u][w]++; // include edge weight from p->u
        }
        for (auto [v, wt] : adj[u]) {
            if (v == p) continue;
            table[0][v] = u; // parent
            dfs(v, u, wt);
        }
    }

    // build binary lifting table
    void build() {
        for (int i = 1; i < MAX; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i-1][j] != -1)
                    table[i][j] = table[i-1][table[i-1][j]];
                else
                    table[i][j] = -1;
            }
        }
    }

    // kth ancestor
    int queryAncestor(int a, int k) {
        for (int i = 0; i < MAX; i++) {
            if (k & (1 << i)) {
                a = table[i][a];
                if (a == -1) break;
            }
        }
        return a;
    }

    // lowest common ancestor
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        a = queryAncestor(a, diff);
        if (a == b) return a;
        for (int i = MAX-1; i >= 0; i--) {
            if (table[i][a] != table[i][b]) {
                a = table[i][a];
                b = table[i][b];
            }
        }
        return table[0][a];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        this->n = n;
        adj.assign(n, {});
        depth.assign(n, 0);
        table.assign(MAX, vector<int>(n, -1));
        cnt.assign(n, vector<int>(W+1, 0));

        // build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // preprocess
        dfs(0, -1, 0);
        build();

        vector<int> ans;
        for (auto &q : queries) {
            int a = q[0], b = q[1];
            int c = lca(a, b);

            int pathLen = depth[a] + depth[b] - 2 * depth[c];

            int maxFreq = 0;
            for (int w = 1; w <= W; w++) {
                int freq = cnt[a][w] + cnt[b][w] - 2*cnt[c][w];
                maxFreq = max(maxFreq, freq);
            }

            ans.push_back(pathLen - maxFreq);
        }
        return ans;
    }
};
