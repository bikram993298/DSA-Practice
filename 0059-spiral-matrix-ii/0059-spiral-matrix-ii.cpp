class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};
        
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, down = n-1;
        int left = 0, right = n-1;
        int counter = 1;
        
        while(top <= down && left <= right) {
            
            for(int i = left; i <= right; i++)
                matrix[top][i] = counter++;
            
            for(int i = top+1; i <= down; i++)
                matrix[i][right] = counter++;
            
            if(top != down) {
                for(int i = right-1; i >= left; i--)
                    matrix[down][i] = counter++;
            }
            
            if(left != right) {
                for(int i = down-1; i > top; i--)
                    matrix[i][left] = counter++;
            }
            
            top++;
            down--;
            left++;
            right--;
        }
        
        return matrix;
    }
};