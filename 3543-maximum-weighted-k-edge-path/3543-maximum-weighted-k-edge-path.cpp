/* Approach: Recursion (DFS) + Memo
Time: O(n * k * t * average number of neighbours)
Space: O(n * k * t)
*/

class Solution {
public:
    int dfs(int node, int edges, int sum,
            vector<vector<pair<int, int>>>& graph, int &k, int &t,
            vector<vector<unordered_map<int, int>>>& dp) {
        // Base Case
        if (edges == k)
			return sum < t ? sum : -1;

        // Already Calculated
        if (dp[node][edges].count(sum))
            return dp[node][edges][sum];

        // try all possibilities: visit all neighbours
        int res = -1;
        for (auto& [neighbor, weight] : graph[node]) {
            int newSum = sum + weight;
            if (newSum >= t) continue;  // pruning
            res = max(res, dfs(neighbor, edges+1, newSum, graph, k, t, dp));
        }
        return dp[node][edges][sum] = res;
    }

    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
 
        vector<vector<pair<int, int>>> graph(n);
        for(auto& e : edges)
            graph[e[0]].push_back({ e[1], e[2] });

       
        vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(k + 1));
        int ans = -1;
        for(int i = 0; i < n; i ++)
            ans = max(ans, dfs(i, 0, 0, graph, k, t, dp));
        return ans;
    }
};