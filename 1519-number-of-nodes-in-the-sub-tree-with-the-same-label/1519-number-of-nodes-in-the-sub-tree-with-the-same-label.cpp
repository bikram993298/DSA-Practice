class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    string labels;

    vector<int> dfs(int node, int parent) {
        vector<int> count(26, 0);

        // include current node label
        count[labels[node] - 'a']++;

        for (int child : adj[node]) {
            if (child == parent) continue;

            vector<int> childCount = dfs(child, node);

            // merge child frequencies
            for (int i = 0; i < 26; i++) {
                count[i] += childCount[i];
            }
        }

        // answer for current node
        ans[node] = count[labels[node] - 'a'];

        return count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels_) {
        labels = labels_;
        adj.resize(n);
        ans.resize(n);

        // build graph
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        return ans;
    }
};