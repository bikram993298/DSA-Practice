class Solution {
public:
    
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int cnt = 0;
        
        for(int i = 0; i < m; i++) {
            
            int low = 0;
            int high = n - 1;
            
            int firstNeg = n;
            
            while(low <= high) {
                
                int mid = low + (high - low) / 2;
                
                if(grid[i][mid] < 0) {
                    firstNeg = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            
            cnt += (n - firstNeg);
        }
        
        return cnt;
    }
};