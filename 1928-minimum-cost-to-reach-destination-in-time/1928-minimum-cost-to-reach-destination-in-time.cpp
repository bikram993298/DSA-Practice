class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        
       //here we have to give minimum cosr pat  but if total time exceed we have to cnotiue,,so in prioery ques,,cots,,time,node
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INF));
        // we cay it visted array because for every node diiferent time..
        // we will ge  less than maxmium time for viaiating eevry node value minmnmum cost

        // Min-heap: {cost, time, city}
    struct cmp {
    bool operator()(const array<int,3>& a, const array<int,3>& b) const {
        if (a[0] != b[0]) return a[0] > b[0]; // cost
        return a[1] > b[1];                  // time
    }
};

priority_queue<array<int,3>, vector<array<int,3>>, cmp> pq;

        // i need to sort on basis of cost ,if cost eqaul hten min time

        dp[0][0] = passingFees[0];
        pq.push({passingFees[0], 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int cost = cur[0];
            int time = cur[1];
            int city = cur[2];

            // If already worse, skip
            if (cost > dp[city][time]) continue;

            for (auto &edge : adj[city]) {
                int nextCity = edge.first;
                int travelTime = edge.second;

                int newTime = time + travelTime;
                if (newTime > maxTime) continue;

                int newCost = cost + passingFees[nextCity];

                if (newCost < dp[nextCity][newTime]) {
                    dp[nextCity][newTime] = newCost;
                    pq.push({newCost, newTime, nextCity});
                }
            }
        }

        int ans = INF;
        // like we dont know what time so we iterate 0 to maxtime allwed and chekc in dp is minimum cost
        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[n - 1][t]);
        }

        return ans == INF ? -1 : ans;
    }
};
