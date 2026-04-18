// class Solution {
// public:
//     void gameOfLife(vector<vector<int>>& board) {
//         int m = board.size(), n = board[0].size();
//         vector<vector<int>> copy = board;

//         vector<pair<int,int>> dirs = {
//             {0,1},{1,0},{0,-1},{-1,0},
//             {1,1},{1,-1},{-1,1},{-1,-1}
//         };

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {

//                 int live = 0;

//                 for (auto &d : dirs) {
//                     int ni = i + d.first;
//                     int nj = j + d.second;

//                     if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
//                         if (copy[ni][nj] == 1) live++;
//                     }
//                 }

//                 if (copy[i][j] == 1) {
//                     if (live < 2 || live > 3)
//                         board[i][j] = 0;
//                 } else {
//                     if (live == 3)
//                         board[i][j] = 1;
//                 }
//             }
//         }
//     }
// };
// extra space 













class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<pair<int,int>> dirs = {
            {0,1},{1,0},{0,-1},{-1,0},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };

        // Step 1: Apply transitions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                // Count neighbors
                for (auto &d : dirs) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                        if (board[ni][nj] == 1 || board[ni][nj] == 2) {
                            live++;
                        }
                    }
                }

                // Apply rules
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        board[i][j] = 2; // live → dead// as the live to dead cell we are changing previously it was live so durng chekc if ewe ifnd 2 mena slive++
                    }
                } else {
                    if (live == 3) {
                        board[i][j] = 3; // dead → live
                    }
                }
            }
        }
// main simultaion is that we will check all the 4 direction then according to cond we will make diffeernt numerings 2,3 becau seliv eto dead and dead to live,,and finally make right,,becuase if u cahnge intially to 0 and 1 it will impoissble to trac dyamic things
        // Step 2: Finalize states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};