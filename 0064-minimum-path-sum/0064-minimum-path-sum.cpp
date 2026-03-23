class Solution {
public:
 vector<vector<int>> dp;

    int solve(int i, int j, int m, int n,vector<vector<int>>& grid) {
        if(i>=m || j>=n) return 1e9;
        // alwasy suse 1e9 instead of int_max;
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int result = INT_MAX;
         result =min(result,grid[i][j]+solve(i+1, j, m, n,grid));
        result =min(result,grid[i][j]+ solve(i, j+1, m, n,grid));

        return dp[i][j] = result;
    }

    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
       
          dp.assign(m, vector<int>(n, -1));
        return solve(0, 0, m, n,grid);
        
        
    }
};
//if there is negactive elemnt then ans can be -1 so you dont use dp assign -1 
// class Solution {
// public:
//     vector<vector<int>> dp;

//     int solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
//         if(i == m-1 && j == n-1) return grid[i][j];
//         if(dp[i][j] != INT_MAX) return dp[i][j];

//         int result = INT_MAX;
//         if(i+1 < m) result = min(result, grid[i][j] + solve(i+1, j, m, n, grid));
//         if(j+1 < n) result = min(result, grid[i][j] + solve(i, j+1, m, n, grid));

//         return dp[i][j] = result;
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         dp.assign(m, vector<int>(n, INT_MAX));
//         return solve(0, 0, m, n, grid);
//     }
// };
