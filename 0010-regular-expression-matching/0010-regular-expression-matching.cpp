class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        // Case 1: current char in pattern is '*'
        if (p[j] == '*') {
            // '*' cannot be the first character (must have a preceding element)
            // Option 1️⃣: not take (skip the x* pair)
            bool notTake = solve(i, j + 1, s, p, dp);

            // Option 2️⃣: take — only if previous pattern char matches current string char
            bool take = (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') &&
                         solve(i - 1 + 1, j, s, p, dp)); // i + 1 just for clarity

            ans = take || notTake;
        }
        else {
            // Normal match: if next pattern char is '*', handle at next step
            bool cur_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

            if (j + 1 < p.size() && p[j + 1] == '*') {
                // Defer handling — move to next position where '*' will be processed
                ans = solve(i, j + 1, s, p, dp);
            } else if (cur_match) {
                ans = solve(i + 1, j + 1, s, p, dp);
            }
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};
