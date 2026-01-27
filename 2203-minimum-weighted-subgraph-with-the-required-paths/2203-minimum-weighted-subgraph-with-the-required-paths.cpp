class Solution {
public:
    const long long INF = 1e18;

    vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
        vector<long long> dist(n, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n), radj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            // so we ahve to calclaute src1 to other distacnes then src 2 t o toer distcaes then main idea is to it is like common part in graaph

            // dist(src1→x)+dist(src2→x)+dist(x→dest)
            // but for making x to dist you have reverse egdes for creating tha because dikstra we use one node to other not for every x to dest

            radj[v].push_back({u, w}); // reversed
        }

    //     Exactly 💯 — the optimal subgraph really looks like a “Y” shape.
    //             src1
    //       \
    //        \
    //         3 ---- 4 ---- 5 ---- dest
    //        /
    //       /
    //    src2


        auto dist1 = dijkstra(n, adj, src1);
        auto dist2 = dijkstra(n, adj, src2);
        auto distToDest = dijkstra(n, radj, dest);

        long long ans = INF;
        for (int i = 0; i < n; i++) {
            if (dist1[i] == INF || dist2[i] == INF || distToDest[i] == INF) continue;
            ans = min(ans, dist1[i] + dist2[i] + distToDest[i]);
        }

        return ans == INF ? -1 : ans;
    }
};
