class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long solve(const vector<int> &nums, int k, int idx, int sum,
                    vector<vector<long long>> &dp) {

        if (idx == nums.size()) {
            return (sum < k) ? 1LL : 0LL;
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        long long take = 0, skip = 0;

        // choose element if sum + nums[idx] stays < k
        if (sum + nums[idx] < k) {
            take = solve(nums, k, idx + 1, sum + nums[idx], dp);
        }

        // skip element
        skip = solve(nums, k, idx + 1, sum, dp);

        return dp[idx][sum] = (take + skip) % MOD;
    }

    int countPartitions(vector<int> &nums, int k) {
        long long totalSum = 0;
        int n = nums.size();
        for (int x : nums) totalSum += x;

        // impossible case
        if (totalSum < 2LL * k) return 0;

        // dp[idx][sum]
        vector<vector<long long>> dp(n, vector<long long>(k, -1));

        // count bad subsets (sum < k)
        long long bad = solve(nums, k, 0, 0, dp);

        // total subsets = 2^n
        long long total = 1;
        for (int i = 0; i < n; i++)
            total = (total * 2) % MOD;

        // final answer = total - 2 * bad
        long long ans = (total - (2LL * bad) ) % MOD;

        return (int)ans;
    }
};
