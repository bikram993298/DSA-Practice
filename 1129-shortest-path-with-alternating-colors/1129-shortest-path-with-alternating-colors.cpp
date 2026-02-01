class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
       
        vector<vector<int>> adj[2];
        adj[0].resize(n);
        adj[1].resize(n);
        
        for (auto& edge : redEdges) adj[0][edge[0]].push_back(edge[1]);
        for (auto& edge : blueEdges) adj[1][edge[0]].push_back(edge[1]);

        vector<int> res(n, -1);
    
        vector<vector<bool>> visited(n, vector<bool>(2, false));

     
        queue<vector<int>> q;

     
        q.push({0, 0, 0});
        q.push({0, 0, 1});
        visited[0][0] = true;
        visited[0][1] = true;

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            int u = curr[0];
            int dist = curr[1];
            int lastCol = curr[2];

           
            if (res[u] == -1 || dist < res[u]) {
                res[u] = dist;
            }

            int nextCol = 1 - lastCol;

            for (int v : adj[nextCol][u]) {
                if (!visited[v][nextCol]) {
                    visited[v][nextCol] = true;
                    q.push({v, dist + 1, nextCol});
                }
            }
        }

        return res;
    }
};