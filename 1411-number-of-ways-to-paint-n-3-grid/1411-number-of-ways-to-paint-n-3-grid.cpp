// // class Solution {
// // public:
// //     int M = 1e9 + 7;
// //     vector<vector<int>> t;

// //     //12 possible first rows
// //     string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY",
// //     "YRY", "GRY", "GYR", "GRG", "GYG"};

// //     int solve(int n, int prev) {
// //         if(n == 0)
// //             return 1;

// //         if(t[n][prev] != -1)
// //             return t[n][prev];

// //         int result = 0;
// //         string last = states[prev];

// //         for(int curr = 0; curr < 12; curr++) {
// //             if(curr == prev)
// //                 continue;

// //             string currPat = states[curr];
// //             bool conflict = false;
// //             for(int col = 0; col < 3; col++) {
// //                 if(currPat[col] == last[col]) {
// //                     conflict = true;
// //                     break;
// //                 }
// //             }

// //             if(!conflict) {
// //                 result = (result + solve(n-1, curr)) % M;
// //             }
// //         }

// //         return t[n][prev] = result;
// //     }

// //     int numOfWays(int n) {
// //         t.resize(n, vector<int>(12, -1)); //T.C : O(n)
// //         int result = 0;

// //         for(int i = 0; i < 12; i++) { //chossing 1st row
// //             //now remaining n-1 rows painting
// //             result = (result + solve(n-1, i)) % M;
// //         }

// //         return result;
// //     }
// // };

class Solution {
public:
    int MOD = 1e9 + 7;

    int dp[5001][3][3][3];

    bool valid(int a, int b, int c) { return (a != b && b != c); }
    // this alid checkin row valid or not

    int solve(int row, int n, int p1, int p2, int p3) {
        //p1,p2,p3 storing previous colmn row values

        if (row == n)
            return 1;

        if (dp[row][p1][p2][p3] != -1)
            return dp[row][p1][p2][p3];

        int ways = 0;

        // current row colors
        for (int c1 = 0; c1 < 3; c1++) {

            for (int c2 = 0; c2 < 3; c2++) {

                for (int c3 = 0; c3 < 3; c3++) {

                    // same row adjacent conflict
                    if (!valid(c1, c2, c3))
                        continue;

                    // vertical conflict
                    if (c1 == p1 || c2 == p2 || c3 == p3)
                        continue;

                    ways = (ways + solve(row + 1, n, c1, c2, c3)) % MOD;
                }
            }
        }

        return dp[row][p1][p2][p3] = ways;
    }

    int numOfWays(int n) {

        memset(dp, -1, sizeof(dp));

        int ans = 0;

        // first row
        for (int c1 = 0; c1 < 3; c1++) {

            for (int c2 = 0; c2 < 3; c2++) {

                for (int c3 = 0; c3 < 3; c3++) {

                    if (!valid(c1, c2, c3))
                        continue;

                    ans = (ans + solve(1, n, c1, c2, c3)) % MOD;
                }
            }
        }

        return ans;
    }
};
// class Solution {
// public:

//     int MOD = 1e9 + 7;

//     int grid[5001][3];

//     int solve(int row, int col, int n) {

//         // move to next row
//         if (col == 3) {

//             row++;
//             col = 0;
//         }

//         // painted whole grid
//         if (row == n)
//             return 1;

//         int ways = 0;

//         // try 3 colors
//         for (int color = 0; color < 3; color++) {

//             bool possible = true;

//             // left check
//             if (col > 0 &&
//                 grid[row][col - 1] == color)
//                 possible = false;

//             // upper check
//             if (row > 0 &&
//                 grid[row - 1][col] == color)
//                 possible = false;

//             if (possible) {

//                 grid[row][col] = color;

//                 ways =
//                     (ways +
//                      solve(row, col + 1, n))
//                     % MOD;
//             }
//         }

//         return ways;
//     }

//     int numOfWays(int n) {

//         return solve(0, 0, n);
//     }
// };