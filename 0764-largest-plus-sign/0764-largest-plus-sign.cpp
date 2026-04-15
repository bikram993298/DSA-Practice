// class Solution {
// public:

//     int check(int i,int j,vector<vector<int>>& grid){
//     int n=grid.size();
//     int k1=0,k2=0,k3=0,k4=0;

//     // upper column
//     int x = i;
//     while(x > 0){
//         x--;
//         if(grid[x][j]) k1++;
//         else break;
//     }

//     // lower column
//     x = i;
//     while(x < n-1){
//         x++;
//         if(grid[x][j]) k2++;
//         else break;
//     }

//     // left
//     int y = j;
//     while(y > 0){
//         y--;
//         if(grid[i][y]) k3++;
//         else break;
//     }

//     // right
//     y = j;
//     while(y < n-1){
//         y++;
//         if(grid[i][y]) k4++;
//         else break;
//     }

//     return min({k1,k2,k3,k4});
// }
//     int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
//         set<pair<int,int>> st;
//         for(int i=0;i<mines.size();i++){
//             st.insert({mines[i][0],mines[i][1]});
//         }
//         // making the whole grid
//         vector<vector<int>> grid(n,vector<int>(n,1));
//          for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(st.count({i,j})){
//                grid[i][j]=0;
//             }
//         }
//       }
//       bool zero=true;

//       // run cehck to find largest plus sign
//       int result=0;
//       for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]==1){
//                 zero=false;
//                 int ans=check(i,j,grid);
//                 result=max(result,ans);

//             }
//         }
//       }



//          return zero==true?0:result+1;
//     }
// };
// // thi give tle approximately 125000000
// // how to think of opitmal appraoch where you are computing same upper many times ,,where same computing manu times then use dp
class Solution {
public:
    int n;
// you can amake also dp[i][3] up,down left ,right in one solve function you can do
    vector<vector<int>> dp_up, dp_down, dp_left, dp_right;

    int up(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || grid[i][j] == 0) return 0;
        if(dp_up[i][j] != -1) return dp_up[i][j];

        return dp_up[i][j] = 1 + up(i - 1, j, grid);
    }

    int down(int i, int j, vector<vector<int>>& grid) {
        if(i >= n || grid[i][j] == 0) return 0;
        if(dp_down[i][j] != -1) return dp_down[i][j];

        return dp_down[i][j] = 1 + down(i + 1, j, grid);
    }

    int left(int i, int j, vector<vector<int>>& grid) {
        if(j < 0 || grid[i][j] == 0) return 0;
        if(dp_left[i][j] != -1) return dp_left[i][j];

        return dp_left[i][j] = 1 + left(i, j - 1, grid);
    }

    int right(int i, int j, vector<vector<int>>& grid) {
        if(j >= n || grid[i][j] == 0) return 0;
        if(dp_right[i][j] != -1) return dp_right[i][j];

        return dp_right[i][j] = 1 + right(i, j + 1, grid);
    }

    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        this->n = n;

        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(auto &m : mines) {
            grid[m[0]][m[1]] = 0;
        }

        dp_up.assign(n, vector<int>(n, -1));
        dp_down.assign(n, vector<int>(n, -1));
        dp_left.assign(n, vector<int>(n, -1));
        dp_right.assign(n, vector<int>(n, -1));

        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int u = up(i, j, grid);
                    int d = down(i, j, grid);
                    int l = left(i, j, grid);
                    int r = right(i, j, grid);

                    int order = min({u, d, l, r});
                    result = max(result, order);
                }
            }
        }

        return result;
    }
};