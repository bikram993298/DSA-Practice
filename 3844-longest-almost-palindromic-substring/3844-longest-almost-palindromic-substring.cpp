class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int solve(string &s, int i, int j) {
        if (i >= j) return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = solve(s, i+1, j-1);
        }

        int left=1+solve(s,i+1,j);
        int right=1+solve(s,i,j-1);

        return memo[i][j]=min(left,right);
    }

    int almostPalindromic(string s) {
        n = s.size();
        memo.assign(n, vector<int>(n, -1));

        int ans = 0;

        // check all substrings
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (solve(s, i, j) <= 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};