
class Solution {
public:
    vector<vector<pair<int,int>>> gr;  // {neighbour, weight}
    vector<vector<long long>> dp;
    int k;

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
    //   Number of nodes=Number of edges+1
      
        int n = edges.size() + 1;
        this->k = k;
        gr.assign(n, {});
        
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            gr[u].push_back({v, w});
            gr[v].push_back({u, w});
        }
        
        dp.assign(n, vector<long long>(2, -1));
        return solve(0, 0, -1);
    }

    long long solve(int node, int isParEdgeRemoved, int parent) {
        if (dp[node][isParEdgeRemoved] != -1)
            return dp[node][isParEdgeRemoved];

        int degree = gr[node].size();
        int edgesToRemove = max(0, degree - k - isParEdgeRemoved);
        long long ans = 0;

        vector<pair<long long,long long>> candidates;
        for (auto &[ne, wt] : gr[node]) {
            if (ne == parent) continue;

            long long dontRemove = solve(ne, 0, node) + wt;
            long long remove = solve(ne, 1, node);
            candidates.push_back({dontRemove, remove});
        }

        // Sort by "loss" if we remove the edge
        sort(candidates.begin(), candidates.end(),
             [](auto &a, auto &b) {
                 return (a.first - a.second) < (b.first - b.second);
             });

        for (int i = 0; i < (int)candidates.size(); i++) {
            long long dontRemove = candidates[i].first;
            long long remove = candidates[i].second;
            if (i < edgesToRemove)
                ans += remove;
            else
                ans += max(dontRemove, remove);
        }

        return dp[node][isParEdgeRemoved] = ans;
    }
};
