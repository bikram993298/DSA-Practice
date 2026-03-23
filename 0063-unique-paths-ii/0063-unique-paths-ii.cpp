class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if(i >= m || j >= n) return 0;
        
        if(grid[i][j] == 1) return 0;
        
        if(i == m-1 && j == n-1 && grid[i][j]==0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i+1, j, m, n, grid);
        int right = solve(i, j+1, m, n, grid);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, m, n, obstacleGrid);
    }
};