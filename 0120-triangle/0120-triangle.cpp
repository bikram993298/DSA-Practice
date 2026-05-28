class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        int n = triangle.size();

        // last row
        if (i == n - 1)
            return triangle[i][j];

        // already computed
        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = solve(i + 1, j, triangle, dp);

        int diagonal = solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return solve(0, 0, triangle, dp);
    }
};