class Solution {
public:
    long long ans = 0;

    long long interactionCosts(int n, vector<vector<int>>& edges,
                               vector<int>& group) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> nodeCount(21, 0);
        for (int g : group) {
            nodeCount[g]++;
        }

        for (int g = 1; g <= 20; g++) {
            dfs(0, -1, g, graph, group, nodeCount);
        }

        return ans;
    }

    int dfs(int curr, int parent, int g, vector<vector<int>>& graph,
            vector<int>& group, vector<int>& nodeCount) {
                //as gorup is 20 we can use for eacg group use dfs then caunt ans

                // now liike in dfs i have to count how for each edges or for each dfs call how many cnt of same nodes then use formula

        int cnt = (group[curr] == g) ? 1 : 0;

        for (int nei : graph[curr]) {
            if (nei != parent) {
                cnt += dfs(nei, curr, g, graph, group, nodeCount);
            }
        }

        ans += 1LL * cnt * (nodeCount[g] - cnt);
        return cnt;
    }
};