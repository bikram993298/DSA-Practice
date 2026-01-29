class Solution {
public:
         bool check(int n, vector<vector<int>>& edges, int threshold, int mid) {
        vector<vector<int>> g(n);

        //  build graph using edges with weight <= mid
        for (auto &e : edges) {
            if (e[2] <= mid) {
                g[e[1]].push_back(e[0]);
            }
        }

        //  enforce outgoing edge constraint
        // for (int i = 0; i < n; i++) {
        //     if ((int)g[i].size() > threshold) {
        //         g[i].resize(threshold);
        //     }
        // }

        //  reverse graph
        // vector<vector<int>> rg(n);
        // for (int u = 0; u < n; u++) {
        //     for (int v : g[u]) {
        //         rg[v].push_back(u);
        //     }
        // }

        //  BFS from node 0
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        // check if all nodes can reach 0
        for (bool x : vis) {
            if (!x) return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        //we will have to use binary serach here beacuse minimize themaximum edge so ,,weight can be min =0 and maxim=according to contraint
//now check funtion will do contruxt graph graph less that agde wegiht of middle and  we hav to check thrresold outgoing so check graph edge size  run bfs from nide wand check if all nodes are visted or not 
         int lo = 0, hi = 0;

        // maximum possible edge weight
        for (auto &e : edges) {
            hi = max(hi, e[2]);
        }

        int ans = -1;

        // binary search on maximum edge weight
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(n, edges, threshold, mid)) {
                ans = mid;
                hi = mid - 1;   // try smaller max edge
            } else {
                lo = mid + 1;
            }
        }

        return ans;

        
    }
};