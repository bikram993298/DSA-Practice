class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int a, vector<vector<int>>& costs) {
        if (i == costs.size())
            return 0;

        if (dp[i][a] != -1)
            return dp[i][a];

        int sendA = INT_MAX;
        int sendB = INT_MAX;

        // send to city A
        if (a < n) {
            sendA = costs[i][0] + solve(i + 1, a + 1, costs);
        }

        // people sent to B = i - a
        if ((i - a) < n) {
            sendB = costs[i][1] + solve(i + 1, a, costs);
        }

        return dp[i][a] = min(sendA, sendB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size() / 2;

        dp.resize(costs.size(), vector<int>(n + 1, -1));

        return solve(0, 0, costs);
    }
};