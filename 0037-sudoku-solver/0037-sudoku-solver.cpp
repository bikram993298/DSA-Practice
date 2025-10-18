class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // If cell is empty, try digits 1–9
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;

                            if (solve(board)) return true; // recursion
                            board[i][j] = '.';             // backtrack
                        }
                    }
                    return false; // no valid number possible
                }
            }
        }
        return true; // completely filled
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        int mask = 1 << (ch - '1');

        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;  // check row
            if (board[i][col] == ch) return false;  // check column
        }

        // Check 3x3 box
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == ch)
                    return false;
            }
        }
        return true;
    }
};
