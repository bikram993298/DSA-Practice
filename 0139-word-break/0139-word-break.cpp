// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());

//         vector<bool> dp(n + 1, false);
//         dp[0] = true; // empty prefix is valid

//         for (int i = 1; i <= n; i++) {
//             for (int j = i; j >= 1; j--) {
//                 // If s[j-1..i-1] is in dict and prefix up to j-1 is breakable
//                 if (dp[j - 1] && dict.count(s.substr(j - 1, i - j + 1))) {
//                     dp[i] = true;
//                     // break; // no need to check smaller j
//                 }
//             }
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    vector<int> dp;

    bool solve(int i, string& s, unordered_set<string>& st) {
        if(i == s.size()) return true;

        if(dp[i] != -1) return dp[i];

        for(int j = i; j < s.size(); j++) {
            string temp = s.substr(i, j - i + 1);

            if(st.count(temp) && solve(j + 1, s, st))
                return dp[i] = 1;
        }

        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp.assign(s.size(), -1);
        return solve(0, s, st);
    }
};