class Solution {
public: 
int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int i, int j, string &s) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = 0;

        if (s[i] == s[j]) {
            int low = i + 1, high = j - 1;

            // find first occurrence
            while (low <= high && s[low] != s[i]) low++;

            // find last occurrence
            while (low <= high && s[high] != s[j]) high--;

            if (low > high) {
                ans = 2 * solve(i+1, j-1, s) + 2;
            }
            else if (low == high) {
                ans = 2 * solve(i+1, j-1, s) + 1;
            }
            else {
                ans = 2 * solve(i+1, j-1, s) - solve(low+1, high-1, s);
            }
        } 
        else {
            ans = solve(i+1, j, s) + solve(i, j-1, s) - solve(i+1, j-1, s);
        }

        return dp[i][j] = (ans % MOD + MOD) % MOD;
    }



    int countPalindromicSubsequences(string s) {
        // https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1




         int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n-1, s);
    }
};