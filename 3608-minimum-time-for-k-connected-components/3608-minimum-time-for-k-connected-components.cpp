class Solution {
public:
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
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
            return true;
        }
        
        bool split(int a, int b) {
            // splitting here just means we don't unite on this edge
            // we track components with reverse logic outside
            return false;
        }
    };

    int minTime(int n, vector<vector<int>>& edges, int k) {
        // Start with all nodes in 1 component
        DSU dsu(n);
        // First union all edges so dsu.components = 1
        for (auto &e : edges)
            dsu.unite(e[0], e[1]);

        // Sort edges descending (largest first)
        sort(edges.begin(), edges.end(), [&](auto &a, auto &b){
            return a[2] > b[2];
        });

        int currComps = 1;
        int result = 0;

        for (auto &e : edges) {
            if (currComps == k) break;
            // Splitting this edge increases components
            currComps++;
            result = max(result, e[2]);
        }

        // If we never reached k components, impossible
        if (currComps != k) return -1;

        return result;
    }
};
