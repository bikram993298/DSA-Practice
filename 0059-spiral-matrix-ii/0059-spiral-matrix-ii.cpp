class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {};
        int m = n;
        vector<vector<int>> matrix(m, vector<int>(n));
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;
        
       
        //id
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top
        int counter = 1;
        while(top <= down && left <= right) {
            //left to right
            
                for(int i = left; i<=right; i++) {
                    matrix[top][i] = counter++;
                }
                
            
            
            //top to down
         
                for(int i = top+1; i<=down; i++) {
                    matrix[i][right] = counter++;
                }
              
            
            
            //right to left
           
                for(int i = right-1; i>=left; i--) {
                    if(top==down) continue;
                    matrix[down][i] = counter++;
                }
            
            
            //down to top
           
                for(int i = down-1; i>top; i--) {
                    if(left==right) continue;
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