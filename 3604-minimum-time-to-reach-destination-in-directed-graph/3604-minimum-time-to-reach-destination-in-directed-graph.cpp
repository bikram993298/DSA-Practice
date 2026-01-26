class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,3>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], en = e[3];
            adj[u].push_back({v, s, en});
            //node to adjacent node,starting time,endin time
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            // t tis time
            // u is node
            pq.pop();

            // if (t != dist[u]) continue;
            if (u == n - 1) return (int)t;

            for (auto &ed : adj[u]) {
                int v = ed[0], s = ed[1], en = ed[2];

                long long depart = max(t, (long long)s);
                if (depart > en) continue;

                long long arrive = depart + 1;

                if (arrive < dist[v]) {
                    dist[v] = arrive;
                    pq.push({arrive, v});
                }
            }
        }

        return -1;
        
    }
};