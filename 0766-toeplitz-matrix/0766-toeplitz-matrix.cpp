// class Solution {
// public:
//       bool solve(int i,int j,vector<vector<int>>& matrix){
//         int same=matrix[i][j];
//         int n=matrix.size();
//         int m=matrix[0].size();
//         while(i<n-1 && j<m-1){
//             i++;
//             j++;
//             if(matrix[i][j]!=same)return false;
//         }


//         return true;
//       }
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {

//         // from ery coloum first elelmt
//         bool result=true;
//         for(int j=0;j<matrix[0].size();j++){
//             bool ans=solve(0,j,matrix);
//            if(ans==false){
//             return false;
//            }
//         }

//          for(int i=0;i<matrix.size();i++){
//             bool ans=solve(i,0,matrix);
//            if(ans==false){
//             return false;
//            }
//         }
//            return true;
//     }
// };

// Every element must be equal to its top-left neighbor
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
// tc o(m*n)