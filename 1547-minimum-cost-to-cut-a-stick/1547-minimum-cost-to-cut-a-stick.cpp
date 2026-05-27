class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (j - i == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        // 0 1 3 4 5 7
        int final = 10e6;
        for (int k = i + 1; k < j; k++) {
            int ans = solve(i, k, cuts, dp) + solve(k, j, cuts, dp) + cuts[j] -
                      cuts[i];
            final = min(final, ans);
        }

        return dp[i][j] = final;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        dp.assign(m, vector<int>(m, -1));
        int ans = solve(0, m - 1, cuts, dp);
        return ans;
    }
};