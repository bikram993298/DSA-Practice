class Solution {
public:
    class DSU {
    public:
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            sz.assign(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    };

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n);

        unordered_map<int, int> factorIndex;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int f = 2; f * f <= x; f++) {
                if (x % f == 0) {
                    if (factorIndex.count(f))
                        dsu.unite(i, factorIndex[f]);
                    else
                        factorIndex[f] = i;

                    while (x % f == 0) x /= f;
                }
            }

            if (x > 1) { // remaining prime factor
                if (factorIndex.count(x))
                    dsu.unite(i, factorIndex[x]);
                else
                    factorIndex[x] = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i)
                ans = max(ans, dsu.sz[i]);
        }

        return ans;
    }
};
