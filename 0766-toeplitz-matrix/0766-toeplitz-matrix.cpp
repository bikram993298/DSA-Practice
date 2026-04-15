class Solution {
public:
      bool solve(int i,int j,vector<vector<int>>& matrix){
        int same=matrix[i][j];
        int n=matrix.size();
        int m=matrix[0].size();
        while(i<n-1 && j<m-1){
            i++;
            j++;
            if(matrix[i][j]!=same)return false;
        }


        return true;
      }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        // from ery coloum first elelmt
        bool result=true;
        for(int j=0;j<matrix[0].size();j++){
            bool ans=solve(0,j,matrix);
           if(ans==false){
            return false;
           }
        }

         for(int i=0;i<matrix.size();i++){
            bool ans=solve(i,0,matrix);
           if(ans==false){
            return false;
           }
        }
           return true;
    }
};