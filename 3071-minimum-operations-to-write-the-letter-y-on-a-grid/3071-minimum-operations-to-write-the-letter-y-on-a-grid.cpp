class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid) {
    int n = grid.size();
    int mid = n / 2;

    // Top part: two diagonals leading to the center
    if (i < mid && (i == j || i + j == n - 1)) return true;

    // Bottom part: vertical line from center down
    if (i >= mid && j == mid) return true;

    return false;
}

    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int count0=0;
        int count1=0;
        int count2=0;
        int not0=0;
        int not1=0;
        int not2=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i,j,grid)){
                    if(grid[i][j]==0)count0++;
                    else if(grid[i][j]==1)count1++;
                    else count2++;
                }else{
                    if(grid[i][j]==0)not0++;
                    else if(grid[i][j]==1)not1++;
                    else not2++;
                }
            }
        }
        int mini=INT_MAX;
        //for taking 0
        int y=count0+count1+count2;
        int noty=not0+not1+not2;
        mini=min(mini,y-count0+(noty-max(not1,not2)));
        //for taking 1;
         mini=min(mini,y-count1+(noty-max(not0,not2)));
        //for takong 2;
         mini=min(mini,y-count2+(noty-max(not1,not0)));


         return mini;
        
    }
};
// to optimise it what we can do that count0,count1 and make a separeate array and not0 not1 make another separatet array or you can make 2d array of them [count][0]->inside y count,


// class Solution {
// public:
//     bool check(int i, int j, vector<vector<int>>& grid) {
//         int n = grid.size();
//         int mid = n / 2;

//         // Top part: two diagonals leading to the center
//         if (i < mid && (i == j || i + j == n - 1)) return true;

//         // Bottom part: vertical line from center down
//         if (i >= mid && j == mid) return true;

//         return false;
//     }

//     int minimumOperationsToWriteY(vector<vector<int>>& grid) {
//         int n = grid.size();

//         // counts[val][0] = count of val in Y
//         // counts[val][1] = count of val outside Y
//         vector<vector<int>> counts(3, vector<int>(2, 0));
//         int yCount = 0, notYCount = 0;

//         // Step 1: count
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 int val = grid[i][j];
//                 if (check(i, j, grid)) {
//                     counts[val][0]++; // inside Y
//                     yCount++;
//                 } else {
//                     counts[val][1]++; // outside Y
//                     notYCount++;
//                 }
//             }
//         }

//         // Step 2: try all assignments
//         int ans = INT_MAX;
//         for (int a = 0; a < 3; a++) {       // Y value
//             for (int b = 0; b < 3; b++) {   // non-Y value
//                 if (a == b) continue;       // must differ
//                 int changeY = yCount - counts[a][0];
//                 int changeNotY = notYCount - counts[b][1];
//                 ans = min(ans, changeY + changeNotY);
//             }
//         }
//         return ans;
//     }
// };
