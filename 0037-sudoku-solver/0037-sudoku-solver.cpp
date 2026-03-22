class Solution {
public:
    bool row[9][9] = {0};
    bool col[9][9] = {0};
    bool box[9][9] = {0};
// backtaracking think in this way that try all posiible combination if blank if valid recurse to new solve funtion return true,if recurse is valid,,think if u tried all combiantion till not get return false,,another you have finised all values then inner thing didi not worked then return true
    bool isValid(int r, int c, char ch) {
        int d = ch - '1';
        int k = (r/3)*3 + (c/3);
        return !row[r][d] && !col[c][d] && !box[k][d];
    }

    bool solve(vector<vector<char>>& b) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(b[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {

                        if(isValid(i, j, ch)) {

                            int d = ch - '1';
                            int k = (i/3)*3 + (j/3);
                            // if it is vvalid update real b and sets ,,row,oloumns and box

                            b[i][j] = ch;
                            row[i][d] = col[j][d] = box[k][d] = 1;

                            if(solve(b)) return true;
                        // backtrsck all
                            b[i][j] = '.';
                            row[i][d] = col[j][d] = box[k][d] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        // initialize from given board
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int d = board[i][j] - '1';// 1 because number from 1 to 9
                    int k = (i/3)*3 + (j/3);
                    row[i][d] = col[j][d] = box[k][d] = 1;
                }
            }
        }

        solve(board);
    }
};