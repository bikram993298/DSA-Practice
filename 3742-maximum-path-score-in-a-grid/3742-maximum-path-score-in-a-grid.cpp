class Solution {
public:
    int n;
    int m;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, vector<vector<int>>& grid, int k) {

        if (i >= n || j >= m || k < 0)
            return -1e9;

        if (i == n - 1 && j == m - 1) {
            if(grid[i][j]==0){
                if(k>=0) return grid[i][j];
                else   return -1e9;
            }else{
                if(k>=1) return grid[i][j];
                else return -1e9;
            }
            
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int res = -1e9;
        // it can go  right and down so path
        if (grid[i][j] == 0) {
            res = solve(i + 1, j, grid, k);
            res = max(res, solve(i, j + 1, grid, k));
        } else if (grid[i][j] == 1) {
            res = 1 + solve(i + 1, j, grid, k - 1);
            res = max(res, 1 + solve(i, j + 1, grid, k - 1));
        } else {
            res = 2 + solve(i + 1, j, grid, k - 1);
            res = max(res, 2 + solve(i, j + 1, grid, k - 1));
        }

        return dp[i][j][k] = res;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        int ans = solve(0, 0, grid, k);
        return ans < 0 ? -1 : ans;
    }
};