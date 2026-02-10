class Solution {
public:


struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (size[a] < size[b]) swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {

        sort(edgeList.begin(), edgeList.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        int q = queries.size();

        vector<vector<int>> qs;

        for (int i = 0; i < q; i++) {
            qs.push_back({
                queries[i][2], // limit
                queries[i][0], // u
                queries[i][1], // v
                i              // original index
            });
        }

        sort(qs.begin(), qs.end());

        DSU dsu(n);
        vector<bool> ans(q, false);

        int edgePtr = 0;

        for (auto& query : qs) {

            int limit = query[0];
            int u = query[1];
            int v = query[2];
            int idx = query[3];

            while (edgePtr < edgeList.size() && edgeList[edgePtr][2] < limit) {

                dsu.unite(edgeList[edgePtr][0], edgeList[edgePtr][1]);

                edgePtr++;
            }

            ans[idx] = (dsu.find(u) == dsu.find(v));
        }

        return ans;
    }
};
