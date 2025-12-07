class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    long long total_sum = 0;
    vector<vector<int>> dp;  

    int solve(int i, vector<int> &nums, int k, int sum) {
        // If current sum has already reached or crossed k,
        // this subset is NOT a "bad" subset -> 0 ways.
        if (sum >= k) return 0;

        // If we've placed all elements and sum < k, this is 1 valid bad subset
        if (i == n) return 1;

        int &res = dp[i][sum];
        if (res != -1) return res;

        long long notake = solve(i + 1, nums, k, sum);            // don't include nums[i]
        long long take   = solve(i + 1, nums, k, sum + nums[i]);  // include nums[i]

        res = (notake + take) % MOD;
        return res;
    }

    long long modpow(long long a, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    int countPartitions(vector<int>& nums, int k) {
        n = (int)nums.size();
        total_sum = 0;
        for (int x : nums) total_sum += x;

        // If total sum is less than 2*k, it's impossible
        // for BOTH groups to have sum >= k.
        if (total_sum < 2LL * k) return 0;

        // dp size: n x k (we only care about sum 0..k-1)
        dp.assign(n, vector<int>(k, -1));

        // Count bad subsets: subsets whose sum < k
        long long badOneSide = solve(0, nums, k, 0);

        // Total ways to assign each element to group1 or group2
        long long totalWays = modpow(2, n);

        // Subtract bad partitions:
        // each bad subset can be either bad group1 or bad group2 -> multiply by 2
        long long ans = (totalWays - 2 * badOneSide) % MOD;
        if (ans < 0) ans += MOD;

        return (int)ans;
    }
};
