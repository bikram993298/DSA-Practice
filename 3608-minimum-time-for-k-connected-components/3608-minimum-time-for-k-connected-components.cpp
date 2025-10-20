#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    int components;
    DSU(int n=0) { init(n); }
    void init(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        components--;
    }
};

class Solution {
public:
    // returns minimum T such that after removing edges with time <= T,
    // the number of connected components >= k.
    // If k > n return -1 (impossible).
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (k > n) return -1;          // impossible
        int maxT = 0;
        for (auto &e : edges) maxT = max(maxT, e[2]);

        // f(T): number of components after removing edges with time <= T
        auto components_after_removals = [&](int T) {
            DSU dsu(n);
            for (auto &e : edges) {
                // edge is active after time T if its failure time > T
                if (e[2] > T) dsu.unite(e[0], e[1]);
            }
            return dsu.components;
        };

        int low = 0, high = maxT;
        // binary search for smallest T with f(T) >= k
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (components_after_removals(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // low is the smallest T with components >= k
        return low;
    }
};
