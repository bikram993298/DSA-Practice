class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // 1,2,3 5fe
        //medain is 2
        //2 4  6  8
        // atfirst we hvae to find median
        vector<int> ans;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(grid[i][j]);
            }
        }


        sort(ans.begin(),ans.end());

        int n1=ans.size();
        int median=ans[n1/2];
        int ans1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int diff=abs(median-grid[i][j]);
                if(diff%x!=0) return -1;
               ans1+=diff/x;

            }
        }

        return ans1;
        
    }
};