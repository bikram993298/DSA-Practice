class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& dist) {

        for (int nei : adj[node]) {

            if (nei == parent)
                continue;

            dist[nei] = dist[node] + 1;

            dfs(nei, node, adj, dist);
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> distX(n, 0), distY(n, 0), distZ(n, 0);

        dfs(x, -1, adj, distX);
        dfs(y, -1, adj, distY);
        dfs(z, -1, adj, distZ);

        int count = 0;

        for (int i = 0; i < n; i++) {

            int a = distX[i];
            int b = distY[i];
            int c = distZ[i];

            // sort manually
            if (a > b)
                swap(a, b);
            if (b > c)
                swap(b, c);
            if (a > b)
                swap(a, b);

            if (1LL*a * a +1LL* b * b == 1LL*c * c)
                count++;
        }

        return count;
    }
};
