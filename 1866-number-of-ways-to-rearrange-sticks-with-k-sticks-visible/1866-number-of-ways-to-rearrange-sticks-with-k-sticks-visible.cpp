class Solution {
public:
    int MOD = 1e9 + 7;
    int nTarget, kTarget;

    long long solve(int i, int j, vector<vector<long long>>& dp) {
        // Base cases
        if (i == nTarget) return j == kTarget ? 1 : 0; // all sticks placed
        if (j > kTarget) return 0; // too many visible sticks

        if (dp[i][j] != -1) return dp[i][j];

        // Option 1: Place the tallest remaining stick at front → visible count increases
        long long take = solve(i + 1, j + 1, dp);

        // Option 2: Place any of the remaining sticks not tallest → visible count stays
        long long notTake = (long long)(i) * solve(i + 1, j, dp) % MOD;

        return dp[i][j] = (take + notTake) % MOD;
    }

    int rearrangeSticks(int n, int k) {
        nTarget = n;
        kTarget = k;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
        return solve(1, 1, dp); // start with first stick placed (tallest visible)
    }
};
