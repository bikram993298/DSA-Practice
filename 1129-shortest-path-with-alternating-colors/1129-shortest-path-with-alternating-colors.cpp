class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
      
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : redEdges) {
            adj[it[0]].push_back({it[1], 1});
        }
        for (auto& it : blueEdges) {
            adj[it[0]].push_back({it[1], 0});
        }

      
        vector<vector<int>> dist(n, vector<int>(2, -1));
        dist[0][0] = 0; 
        dist[0][1] = 0; 
        
        queue<pair<int, int>> q; 
        q.push({0, 1});
        q.push({0, 0}); 

        while (!q.empty()) {
            auto [u, lastCol] = q.front();
            q.pop();

            for (auto& [v, edgeCol] : adj[u]) {
                
                if (edgeCol != lastCol && dist[v][edgeCol] == -1) {
                    dist[v][edgeCol] = dist[u][lastCol] + 1;
                    q.push({v, edgeCol});
                }
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1 && dist[i][1] == -1) {
                res[i] = -1;
            } else if (dist[i][0] == -1) {
                res[i] = dist[i][1];
            } else if (dist[i][1] == -1) {
                res[i] = dist[i][0];
            } else {
                res[i] = min(dist[i][0], dist[i][1]);
            }
        }
        return res;
    }
};