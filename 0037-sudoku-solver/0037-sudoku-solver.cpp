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

                            if (solve(board)) return true; // proceed recursively
                             board[i][j] = '.';        // backtrack
                        }
                    }
                    return false; // no digit fits here → backtrack
                }
            }
        }
        return true; // all cells filled successfully
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            // check row and column
            if (board[row][i] == ch || board[i][col] == ch)
                return false;

            // check 3×3 sub-box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == ch)
                return false;
        }
        return true;
    }
};
