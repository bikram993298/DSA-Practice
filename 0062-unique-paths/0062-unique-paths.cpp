class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, int m, int n) {
        if(i == m-1 && j == n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int result = 0;
         result += solve(i+1, j, m, n);
         result += solve(i, j+1, m, n);

        return dp[i][j] = result;
    }

    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return solve(0, 0, m, n);
    }
};

//2^(m+n)
//stack o(m+n)
//with memo
//m*n
//dp table of size m * n → O(m * n)

////Recursion stack depth in worst case = O(m + n)

//SC = O(m * n + m + n) ≈ O(m * n)