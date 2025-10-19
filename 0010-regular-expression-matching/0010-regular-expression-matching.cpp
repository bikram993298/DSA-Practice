class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(0, 0, s, p, dp);
    }

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (j == p.size()) return i == s.size();  // both exhausted
        if (dp[i][j] != -1) return dp[i][j];

        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Skip or use '*'
            ans = solve(i, j + 2, s, p, dp) || (first_match && solve(i + 1, j, s, p, dp));
        } else {
            // Direct match
            ans = first_match && solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = ans;
    }
};
