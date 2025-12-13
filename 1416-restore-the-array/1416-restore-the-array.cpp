class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> dp;
    string s;
    int k, n;

    int solve(int i) {
        if (i == n) return 1;          
        if (s[i] == '0') return 0;     

        if (dp[i] != -1) return dp[i];

        long long num = 0;
        long long ways = 0;

        for (int j = i; j < n; j++) {
            num = num * 10 + (s[j] - '0');
            if (num > k) break;

            ways = (ways + solve(j + 1)) % MOD;
        }

        return dp[i] = ways;
    }

    int numberOfArrays(string str, int K) {
        s = str;
        k = K;
        n = s.size();
        dp.assign(n, -1);
        return solve(0);
    }
};
