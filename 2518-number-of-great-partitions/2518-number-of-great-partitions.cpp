class Solution {
public:
    static const long long MOD = 1000000007;
    long long dp[1005][1005]; 
    // dp[idx][sum] = number of subsets from idx with current sum = sum (sum < k)

    long long solve(vector<int> &nums, int k, int idx, int sum) {
        if (idx == nums.size()) {
            return (sum < k) ? 1 : 0;
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        long long choice1 = 0, choice2 = 0;

        // take the element only if sum stays < k
        if (sum + nums[idx] < k) {
            choice1 = solve(nums, k, idx + 1, sum + nums[idx]);
        }

        // skip the element
        choice2 = solve(nums, k, idx + 1, sum);

        return dp[idx][sum] = (choice1 + choice2) % MOD;
    }

    int countPartitions(vector<int> &nums, int k) {
        long long totalSum = 0;
        for (int n : nums) totalSum += n;

        if (totalSum < 2LL * k) return 0;   // no valid partitions possible

        memset(dp, -1, sizeof(dp));

        // count subsets with sum < k
        long long bad = solve(nums, k, 0, 0);

        // total subsets = 2^n
        long long total = 1;
        for (int i = 1; i <= nums.size(); i++) total = (total * 2) % MOD;

        // final answer = total - 2 * bad
        long long ans = (total - (2 * bad) % MOD + MOD) % MOD;

        return ans;
    }
};
