class Solution {
public:
    vector<int> dp;

    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    int solve(int i, string& s) {
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(s, i, j)) {
                int cost = 1 + solve(j + 1, s);
                mini = min(mini, cost);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        dp.assign(n, -1);

        return solve(0, s) - 1; // subtract 1 for cuts
    }
};