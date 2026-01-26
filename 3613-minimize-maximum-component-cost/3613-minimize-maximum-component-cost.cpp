class DSU {
public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int k, int X) {
        DSU dsu(n);

        // connect only edges with weight <= X
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w <= X) dsu.unite(u, v);
        }

        // count components
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) comp++;
        }

        // example: want <= k components
        return comp <= k;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 0;
        for (auto &e : edges) hi = max(hi, e[2]);

        int ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(n, edges, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
