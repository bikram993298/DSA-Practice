
class DSU {
public:
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        components--;
    }
};

class Solution {
public:
    // true if after removing edges with time <= T (i.e. keeping edges with time > T)
    // the number of components is >= k
    bool canReduceToK(int n, vector<vector<int>>& edges, int k, int T) {
        DSU dsu(n);
        for (auto &e : edges) {
            // edge is active AFTER time T iff its failure time > T
            if (e[2] > T)
                dsu.unite(e[0], e[1]);
        }
        return dsu.components >= k;
    }

    int minimumTime(int n, vector<vector<int>>& edges, int k) {
        if (k > n) return -1; // impossible

        int low = 0, high = 0;
        for (auto &e : edges)
            high = max(high, e[2]);

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canReduceToK(n, edges, k, mid)) {
                ans = mid;
                high = mid - 1; // try smaller T
            } else {
                low = mid + 1;  // need larger T
            }
        }
        return ans;
    }
};
