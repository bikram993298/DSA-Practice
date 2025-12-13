class Solution {
public:
    static const int MOD = 1e9 + 7;
    int low, high, zero, one;
    vector<int> dp;

    int solve(int len) {
        if (len > high) return 0;

        if (dp[len] != -1)
            return dp[len];

        long long ways = 0;

        // count current string ONCE if valid
        if (len >= low && len <= high) {
            ways = 1;
        }

        // explore both extensions
        ways = (ways + solve(len + zero)) % MOD;
        ways = (ways + solve(len + one)) % MOD;

        return dp[len] = ways;
    }

    int countGoodStrings(int low_, int high_, int zero_, int one_) {
        low = low_;
        high = high_;
        zero = zero_;
        one = one_;

        dp.assign(high + 1, -1);
        return solve(0);
    }
};
