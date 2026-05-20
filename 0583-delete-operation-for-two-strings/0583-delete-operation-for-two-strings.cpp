class Solution {
public:

    int dp[501][501];

    int solve(int i,
              int j,
              string& s1,
              string& s2) {

        int n = s1.size();
        int m = s2.size();

        // base case
        if(i == n || j == m)
            return 0;

        // memoization
        if(dp[i][j] != -1)
            return dp[i][j];

        // characters match
        if(s1[i] == s2[j]) {

            return dp[i][j] =
                   1 + solve(i + 1,
                             j + 1,
                             s1,
                             s2);
        }

        // skip one character
        return dp[i][j] =
               max(
                   solve(i + 1, j, s1, s2),
                   solve(i, j + 1, s1, s2)
               );
    }

    int minDistance(string word1,
                    string word2) {

        memset(dp, -1, sizeof(dp));

        int lcs = solve(0, 0, word1, word2);

        return
        (word1.size() - lcs)
        +
        (word2.size() - lcs);
    }
};