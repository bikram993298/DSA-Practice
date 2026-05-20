class Solution {
public:
    long long dp[100001][2];

    long long solve(int i, int sign, vector<int>& nums) {

        int n = nums.size();

        if (i == n)
            return 0;

        if (dp[i][sign] != -1)
            return dp[i][sign];

        long long ans;

        // current gets +
        if (sign == 0) {

            ans = nums[i] + max(solve(i + 1, 0, nums), solve(i + 1, 1, nums));
        }

        // current gets -
        else {

            ans = -nums[i] + solve(i + 1, 0, nums);
        }

        return dp[i][sign] = ans;
    }

    long long maximumTotalCost(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, nums);
    }
};