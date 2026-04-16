class Solution {
public:
    int n;
    vector<double> prefix;
    vector<vector<double>> dp;

    double solve(int i, int k, vector<int>& nums) {
        // base case
        if (k == 1) {
            return (prefix[n] - prefix[i]) / (n - i);
        }

        if (dp[i][k] != -1) return dp[i][k];

        double ans = 0;

        // try all partitions
        for (int j = i; j <= n - k; j++) {
            double avg = (prefix[j + 1] - prefix[i]) / (j - i + 1);
            ans = max(ans, avg + solve(j + 1, k - 1, nums));
        }

        return dp[i][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();

        // prefix sum
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        dp.assign(n, vector<double>(k + 1, -1));

        return solve(0, k, nums);
    }
};