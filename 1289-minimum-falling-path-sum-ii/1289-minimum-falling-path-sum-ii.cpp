class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dp;

    int solve(int r,int c,vector<vector<int>>& grid){

        if(r==n) return 0;

        // memo check
        if(dp[r][c] != INT_MAX) return dp[r][c];

        int take=0;
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            if(i!=c){
                take=grid[r][c]+solve(r+1,i,grid);
                res=min(take,res);
            }
        }

        return dp[r][c] = res;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        // initialize memo table
        dp.assign(n, vector<int>(m, INT_MAX));

        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,grid[0][i]+solve(1,i,grid));
        }

        return ans;
    }
};
