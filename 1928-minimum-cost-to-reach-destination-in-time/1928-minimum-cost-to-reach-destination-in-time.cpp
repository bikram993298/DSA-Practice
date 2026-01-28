#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        const int INF = 1e9;
        // minTime[city] will store the minimum time taken to reach 'city' 
        // with a cost better than or equal to what we've seen.
        vector<int> minTime(n, INF);

        // Min-heap: {cost, time, city}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push({passingFees[0], 0, 0});
        minTime[0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0];
            int time = cur[1];
            int city = cur[2];

            // If we reach the destination, it's the minimum cost because of the Min-Heap
            if (city == n - 1) return cost;

            for (auto& edge : adj[city]) {
                int nextCity = edge.first;
                int travelTime = edge.second;
                int newTime = time + travelTime;

                if (newTime <= maxTime) {
                    // PRUNING: Only push to PQ if this path offers a better time 
                    // than any other path with a cost we've seen so far.
                    if (newTime < minTime[nextCity]) {
                        minTime[nextCity] = newTime;
                        pq.push({cost + passingFees[nextCity], newTime, nextCity});
                    }
                }
            }
        }

        return -1;
    }
};