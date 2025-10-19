class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (j == p.size()) return i == s.size();  
        if (dp[i][j] != -1) return dp[i][j];

        bool prev_match = (i > 0 && j > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
        bool ans;

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Skip or use '*'
            ans = solve(i, j + 2, s, p, dp) || (prev_match && solve(i + 1, j, s, p, dp));
        } else {
            // Direct match
            ans = prev_match && solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};
