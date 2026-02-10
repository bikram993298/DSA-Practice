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



// ## ✅ Checking Existence of Edge Length Limited Paths II

// This is **Hard version of 1697**.

// ---

// # 🧠 What Changed From Part I

// ### Part I

// 👉 Offline queries
// 👉 Sort edges + queries
// 👉 DSU sweep → works

// ---

// ### Part II

// 👉 Queries come **online**
// 👉 Cannot sort queries
// 👉 Need data structure to answer anytime

// ---

// # 🔥 Core Idea

// Use:

// ```
// Minimum Spanning Tree + Binary Lifting + LCA + Max Edge Query
// ```

// ---

// # 🧠 Why MST Works

// Key property:

// 👉 In MST
// Path between u → v
// Minimizes maximum edge weight among all possible paths.

// So if MST path max edge < limit → path exists in original graph.

// ---

// # 🧩 Final Plan

// ### Step 1

// Build MST using Kruskal + DSU.

// ---

// ### Step 2

// Convert MST into tree.

// ---

// ### Step 3

// Binary lifting preprocessing:
// Store:

// ```
// parent[k][v]
// maxEdge[k][v]
// ```

// ---

// ### Step 4

// For query(u, v, limit):
// Find max edge on MST path → compare with limit.

// ---

// # ✅ Full C++ Code

// ---

// ## ⭐ DSU

// ```cpp
// struct DSU {
//     vector<int> parent, size;

//     DSU(int n) {
//         parent.resize(n);
//         size.assign(n, 1);
//         for (int i = 0; i < n; i++)
//             parent[i] = i;
//     }

//     int find(int x) {
//         if (parent[x] == x) return x;
//         return parent[x] = find(parent[x]);
//     }

//     bool unite(int a, int b) {
//         a = find(a);
//         b = find(b);
//         if (a == b) return false;

//         if (size[a] < size[b]) swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//         return true;
//     }
// };
// ```

// ---

// ## ⭐ Main Class

// ```cpp
// class DistanceLimitedPathsExist {
// public:

//     int LOG = 20;

//     vector<vector<pair<int,int>>> tree;
//     vector<vector<int>> parent;
//     vector<vector<int>> maxEdge;
//     vector<int> depth;

//     void dfs(int u, int p, int w) {

//         parent[0][u] = p;
//         maxEdge[0][u] = w;

//         for (auto [v, wt] : tree[u]) {
//             if (v == p) continue;

//             depth[v] = depth[u] + 1;
//             dfs(v, u, wt);
//         }
//     }

//     DistanceLimitedPathsExist(int n, vector<vector<int>>& edges) {

//         DSU dsu(n);
//         sort(edges.begin(), edges.end(),
//              [](auto &a, auto &b){
//                  return a[2] < b[2];
//              });

//         tree.assign(n, {});
//         parent.assign(LOG, vector<int>(n, -1));
//         maxEdge.assign(LOG, vector<int>(n, 0));
//         depth.assign(n, 0);

//         // Build MST
//         for (auto &e : edges) {
//             if (dsu.unite(e[0], e[1])) {
//                 tree[e[0]].push_back({e[1], e[2]});
//                 tree[e[1]].push_back({e[0], e[2]});
//             }
//         }

//         dfs(0, -1, 0);

//         // Binary lifting build
//         for (int k = 1; k < LOG; k++) {
//             for (int v = 0; v < n; v++) {

//                 if (parent[k-1][v] == -1) continue;

//                 parent[k][v] = parent[k-1][ parent[k-1][v] ];
//                 maxEdge[k][v] = max(
//                     maxEdge[k-1][v],
//                     maxEdge[k-1][ parent[k-1][v] ]
//                 );
//             }
//         }
//     }

//     int maxEdgeQuery(int u, int v) {

//         if (depth[u] < depth[v]) swap(u, v);

//         int ans = 0;

//         int diff = depth[u] - depth[v];

//         for (int k = 0; k < LOG; k++) {
//             if (diff & (1 << k)) {
//                 ans = max(ans, maxEdge[k][u]);
//                 u = parent[k][u];
//             }
//         }

//         if (u == v) return ans;

//         for (int k = LOG-1; k >= 0; k--) {
//             if (parent[k][u] != parent[k][v]) {

//                 ans = max(ans, maxEdge[k][u]);
//                 ans = max(ans, maxEdge[k][v]);

//                 u = parent[k][u];
//                 v = parent[k][v];
//             }
//         }

//         ans = max(ans, maxEdge[0][u]);
//         ans = max(ans, maxEdge[0][v]);

//         return ans;
//     }

//     bool query(int p, int q, int limit) {

//         return maxEdgeQuery(p, q) < limit;
//     }
// };
// ```

// ---

// # ⏱ Complexity

// ### Preprocessing

// ```
// MST build      : O(E log E)
// LCA preprocess : O(N log N)
// ```

// ### Each Query

// ```
// O(log N)
// ```

// ---

// # 🔥 Pattern Recognition

// If problem says:

// ```
// Online queries
// Edge weight threshold
// Connectivity path check
// ```

// Think:

// ```
// MST + LCA + Binary Lifting
// ```

// ---

// # ⭐ Why Hard Version Exists

// To prevent:
// ❌ Offline sorting trick
// Forces:
// ✅ Graph theory + LCA + MST

// ---

// If you want, I can explain:

// * Why MST guarantees optimal max-edge path
// * Visual MST path proof
// * When MST trick fails

// Just tell 👍
