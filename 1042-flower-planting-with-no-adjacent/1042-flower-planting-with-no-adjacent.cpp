class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        // 1-based graph
        vector<vector<int>> graph(n + 1);

        // build graph
        for (int i = 0; i < paths.size(); i++) {
            int u = paths[i][0];
            int v = paths[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // 1-based answer array
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // used[color] tells whether this flower is already used
            vector<int> used(5, 0);

            for (int j = 0; j < graph[i].size(); j++) {
                int neighbor = graph[i][j];

                int flower = ans[neighbor];
                used[flower] = 1;
            }

            // choose first available flower from 1 to 4
            for (int color = 1; color <= 4; color++) {
                if (used[color] == 0) {
                    ans[i] = color;
                    break;
                }
            }
        }

        // return only 1-based values
        vector<int> result;

        for (int i = 1; i <= n; i++) {
            result.push_back(ans[i]);
        }

        return result;
    }
};