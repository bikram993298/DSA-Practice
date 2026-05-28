class Solution {
public:
    int S;

    int solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        // Out of possible range
        if (target > S || target < -S)
            return 0;
        // Used all elements
        if (i == nums.size()) {

            // Successfully formed target
            if (target == 0)
                return 1;

            return 0;
        }

        // Memoization
        if (dp[i][target + S] != INT_MIN)
            return dp[i][target + S];

        // Put '+' before nums[i]
        int plus = solve(nums, target - nums[i], i + 1, dp);

        // Put '-' before nums[i]
        int minus = solve(nums, target + nums[i], i + 1, dp);

        return dp[i][target + S] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        // Total sum
        S = accumulate(nums.begin(), nums.end(), 0);

        /*
            target range:
            [-S ... +S]

            Shift by +S
            to avoid negative indexing
        */

        vector<vector<int>> dp(n, vector<int>(2 * S + 1, INT_MIN));

        return solve(nums, target, 0, dp);
    }
};