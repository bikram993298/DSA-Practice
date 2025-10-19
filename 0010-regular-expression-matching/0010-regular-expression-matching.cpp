class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base case: pattern finished
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        // Check if current s[i] matches p[j]
        bool prev_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // If next char in pattern is '*', we have two choices
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // 1️⃣ Skip "x*" part entirely → move pattern by 2
            // 2️⃣ If current matches → move string by 1, pattern stays
            ans = solve(i, j + 2, s, p, dp) || (prev_match && solve(i + 1, j, s, p, dp));
        } 
        else {
            // Direct match → move both forward
            if (prev_match)
                ans = solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};
