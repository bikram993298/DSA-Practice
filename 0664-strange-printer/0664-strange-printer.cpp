class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, string &s) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1 + solve(i + 1, j, s);

        for (int k = i+1 ; k <= j; k++) {
            if (s[k] == s[i]) {
                ans = min(ans, 
                    solve(i+1 , k , s) + solve(k+1, j, s)
                );
            }
        }

        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size() - 1, s);
    }
};