class Solution {
public:
    int dp[601][101][101];

    int solve(int idx, int m, int n, vector<string>& strs) {

        if(m<0 || n<0) return -1e9;
       

        if (idx == strs.size()) {
            return 0;
        }


      
        if (dp[idx][m][n] != -1) {
            return dp[idx][m][n];
        }

      
        int zeros = 0, ones = 0;

        for (char ch : strs[idx]) {
            if (ch == '0')
                zeros++;
            else
                ones++;
        }

        // option 1 -> skip current string
        int notTake = solve(idx + 1, m, n, strs);

        // option 2 -> take current string
        int take = 0;

            take = 1 + solve(idx + 1, m - zeros, n - ones, strs);
    

        return dp[idx][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        memset(dp, -1, sizeof(dp));

        return solve(0, m, n, strs);
    }
};