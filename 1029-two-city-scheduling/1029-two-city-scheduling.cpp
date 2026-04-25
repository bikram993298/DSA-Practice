class Solution {
public:
    int n;   // total number of people
    vector<vector<vector<int>>> dp;

    int solve(int i, int a, int b, vector<vector<int>>& costs) {

        // all people processed
        if (i == n) {
            if (a == n / 2 && b == n / 2)
                return 0;

            return 1e9; // invalid case
        }

        if (dp[i][a][b] != -1)
            return dp[i][a][b];

        int sendA = 1e9;
        int sendB = 1e9;

        // send current person to city A
        if (a < n / 2) {
            sendA = costs[i][0] + solve(i + 1, a + 1, b, costs);
        }

        // send current person to city B
        if (b < n / 2) {
            sendB = costs[i][1] + solve(i + 1, a, b + 1, costs);
        }

        return dp[i][a][b] = min(sendA, sendB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {

        n = costs.size(); // total people

        dp.resize(n,
                  vector<vector<int>>(n + 1,
                  vector<int>(n + 1, -1)));

        return solve(0, 0, 0, costs);
    }
};