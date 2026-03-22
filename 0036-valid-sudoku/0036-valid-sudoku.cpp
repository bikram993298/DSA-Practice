// // // class Solution {
// // // public:
// // // // brute forceo (81* 81)
// // // // o(81)


// // //     bool isValidSudoku(vector<vector<char>>& board) {
        
// // //         // rows
// // //         for(int i = 0; i < 9; i++) {
// // //             unordered_set<char> st;
// // //             for(int j = 0; j < 9; j++) {
// // //                 char c = board[i][j];
// // //                 if(c == '.') continue;
// // //                 if(st.count(c)) return false;
// // //                 st.insert(c);
// // //             }
// // //         }
        
// // //         // columns
// // //         for(int j = 0; j < 9; j++) {
// // //             unordered_set<char> st;
// // //             for(int i = 0; i < 9; i++) {
// // //                 char c = board[i][j];
// // //                 if(c == '.') continue;
// // //                 if(st.count(c)) return false;
// // //                 st.insert(c);
// // //             }
// // //         }
        
// // //         // 3x3 boxes
// // //         for(int sr = 0; sr < 9; sr += 3) {
// // //             for(int sc = 0; sc < 9; sc += 3) {
                
// // //                 unordered_set<char> st;
                
// // //                 for(int i = sr; i < sr + 3; i++) {
// // //                     for(int j = sc; j < sc + 3; j++) {
// // //                         char c = board[i][j];
// // //                         if(c == '.') continue;
// // //                         if(st.count(c)) return false;
// // //                         st.insert(c);
// // //                     }
// // //                 }
// // //             }
// // //         }
        
// // //         return true;
// // //     }
// // // };
























// // -


// // 1. No duplicate in a row  
// // 2. No duplicate in a column  
// // 3. No duplicate in a 3×3 box  
// // ```



// // # 🔥 Smart Thinking (THIS is the intuition)

// // Instead ask:

// // ```text
// // “Have I already seen this number here?”
// // ```

// // 👉 If yes → invalid
// // 👉 If no → mark it

// // ---

// // # 🧩 So we store memory

// // ```cpp
// // bool row[9][9];
// // // row [i][j] denoting that i is row number and j is digit,, if here are 10 cross soduko and j denotes number here only 1 to 9 numbers
// // // row[i][j] gives if in iht row jth digit is present or not
// // bool col[9][9];
// // bool box[9][9];
// // // same box is numbered 
// // ### 🧠 Think of 3×3 boxes like this:

// // ```
// // 0 1 2
// // 3 4 5
// // 6 7 8
// // ```
// // ```
// // so to find box number i/3*3+j/3;

// // ---

// // ## 🔍 Meaning of each

// // ### 👉 row[i][d]

// // ```text
// // Have I seen digit d in row i?
// // ```

// // ---

// // ### 👉 col[j][d]

// // ```text
// // Have I seen digit d in column j?
// // ```

// // ---

// // ### 👉 box[k][d]

// // ```text
// // Have I seen digit d in box k?
// // ```

// // ---

// // # ⚡ Now walk through code line-by-line

// // ---

// // ## 🔁 Loop over every cell

// // ```cpp
// // for(int i = 0; i<9; i++) {
// //     for(int j = 0; j<9; j++) {
// // ```

// // 👉 Visit each cell once

// // ---

// // ## ⏭ Skip empty cells

// // ```cpp
// // if(board[i][j] == '.') continue;
// // ```

// // 👉 Ignore blanks

// // ---

// // ## 🔢 Convert char → index

// // ```cpp
// // int digit = board[i][j] - '0' - 1;
// // ```

// // ### Example:

// // ```text
// // '1' → 0  
// // '5' → 4  
// // '9' → 8
// // ```

// // 👉 Why `-1`?
// // Because arrays are **0-based**

// // ---

// // ## 🔥 Most Important Line (BOX INDEX)

// // ```cpp
// // int boxIndex = (i/3)*3 + (j/3);
// // ```

// // ---



// // ---

// // ### 🔍 Example:

// // Cell `(i=5, j=7)`:

// // ```text
// // i/3 = 1  
// // j/3 = 2  

// // boxIndex = 1*3 + 2 = 5
// // ```

// // 👉 That’s the correct 3×3 box

// // ---

// // # 🚨 Main Check (heart of solution)

// // ```cpp
// // if(row[i][digit] || col[j][digit] || box[boxIndex][digit])
// //     return false;
// // ```

// // ---

// // ### 🧠 Meaning:

// // 👉 If this digit is already:

// // * in same row ❌
// // * in same column ❌
// // * in same box ❌

// // --
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         bool row[9][9] = {0};// 0 mean 0 → false  
// //1 → true
//         bool col[9][9] = {0};
//         bool box[9][9] = {0};
//         for(int i = 0; i<9; i++) {
//             for(int j = 0; j<9; j++) {
//                 if(board[i][j] == '.') continue;
                
//                 int digit     = board[i][j] - '0' - 1; //(-1 because indexes staring from 0 )
                
//                 //we have numbered 9 boxes of (3*3) as 0, 1, 2, 3, 4 ... 9 (see the diagram below)
//                 int boxIndex  = (i/3)*3 + (j/3);
                
//                 if(row[i][digit] || col[j][digit] || box[boxIndex][digit]) return false;
//                 row[i][digit]        = true;
//                 col[j][digit]        = true;
//                 box[boxIndex][digit] = true;
                
//             }
//         }
        
//         return true;
//     }
// };
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {0};//0th if i found 1 to 9 any number or not 
        // how u though of this intiiton is i ned to check in row 
        bool col[9][10] = {0};
        bool box[9][10] = {0};
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                
                int digit = board[i][j] - '0';  // 1 → 9
                // by i and j you will find that in that row index and coloumn index and box index then check if digit oreviously or not
                int boxIndex = (i/3)*3 + (j/3);
                
                if(row[i][digit] || col[j][digit] || box[boxIndex][digit])
                    return false;
                
                row[i][digit] = true;
                col[j][digit] = true;
                box[boxIndex][digit] = true;
            }
        }
        
        return true;
    }
};