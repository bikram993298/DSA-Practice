class Solution {
public:
    int initial_sum = 0;
    vector<int> depthArr;    // distance (edges) from root to each node
    vector<int> subtree;     // subtree sizes
    vector<int> ans;         // final distances for all nodes

    void dfsDepth(vector<vector<int>> &adj, int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            depthArr[v] = depthArr[u] + 1; // distance = parent's depth + 1
            dfsDepth(adj, v, u);
        }
    }

    int dfsSubtree(vector<vector<int>> &adj, int u, int parent) {
        subtree[u] = 1;
        for (int v : adj[u]) {
            if (v == parent) continue;
            subtree[u] += dfsSubtree(adj, v, u);
        }
        return subtree[u];
    }

    void dfsReroot(vector<vector<int>> &adj, int u, int parent, int n) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            ans[v] = ans[u] - subtree[v] + (n - subtree[v]);
            dfsReroot(adj, v, u, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        depthArr.resize(n, 0);
        subtree.resize(n, 0);
        ans.resize(n, 0);

        // Step 1: compute depth of each node (from root = 0)
        dfsDepth(adj, 0, -1);

        // Step 2: compute total sum of depths = sum of distances from root
        for (int i = 0; i < n; i++) {
            initial_sum += depthArr[i];
        }

        // Step 3: compute subtree sizes
        dfsSubtree(adj, 0, -1);

        // Step 4: reroot answers
        ans[0] = initial_sum;
        dfsReroot(adj, 0, -1, n);

        return ans;
    }
};
