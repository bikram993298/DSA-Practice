class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int i, int a, int b, vector<vector<int>>& costs) {
        
        if (i == costs.size()) {
            if (a == n && b == n)
                return 0;
            return 1e9;
        }

        if (dp[i][a][b] != -1)
            return dp[i][a][b];

        int sendA = 1e9;
        int sendB = 1e9;

        if (a < n) {
            sendA = costs[i][0] + solve(i + 1, a + 1, b, costs);
        }

        if (b < n) {
            sendB = costs[i][1] + solve(i + 1, a, b + 1, costs);
        }

        return dp[i][a][b] = min(sendA, sendB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size() / 2;

        int total = costs.size();

        dp.resize(total,
                  vector<vector<int>>(n + 1,
                  vector<int>(n + 1, -1)));

        return solve(0, 0, 0, costs);
    }
};