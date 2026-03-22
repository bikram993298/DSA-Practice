class Solution {
public:

    bool isValid(vector<vector<char>>& b, int r, int c, char ch) {
        for(int i = 0; i < 9; i++) {
            if(b[r][i] == ch) return false;
            if(b[i][c] == ch) return false;
        }

        int sr = (r/3)*3, sc = (c/3)*3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(b[sr+i][sc+j] == ch) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& b) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(b[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {

                        if(isValid(b, i, j, ch)) {
                            b[i][j] = ch;

                            if(solve(b)) return true;

                            b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};