class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base case: pattern finished
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];

        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        bool ans = false;

        // If next character in pattern is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Option 1: skip the x* entirely
            // Option 2: use one more occurrence if first_match
            ans = solve(i, j + 2, s, p, dp) || (first_match && solve(i + 1, j, s, p, dp));
        } 
        else {
            // Direct match (move both forward)
            ans = first_match && solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};
