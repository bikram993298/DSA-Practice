class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(1 << n, -1));

        
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            q.push({i, mask});
            dist[i][mask] = 0;
        }

        while (!q.empty()) {
            auto [node, mask] = q.front();
            q.pop();

            if (mask == target) {
                return dist[node][mask];
            }

            for (int neigh : graph[node]) {
                int newMask = mask | (1 << neigh);

                if (dist[neigh][newMask] == -1) {
                    dist[neigh][newMask] = dist[node][mask] + 1;
                    q.push({neigh, newMask});
                }
            }
        }

        return 0;
    }
};
