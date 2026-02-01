class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> blocked, visited;

    int dfs(int node) {
        visited[node] = true;
        int cnt = 0;

        for (int nei : adj[node]) {
            if (!visited[nei] && !blocked[nei]) {
                cnt +=1+ dfs(nei);
            }
        }
        return cnt;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adj.resize(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        blocked.resize(n, false);
        visited.resize(n, false);

        for (int x : restricted)
            blocked[x] = true;

        return dfs(0)+1;
    }
};
