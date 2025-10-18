class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int> row(9,0);
        vector<int> col(9,0);
        vector<int> box(9,0);




        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(board[i][j]=='.')continue;

                int digit=board[i][j]-'1';
              
                int mask=1<<digit;
                int index=(i / 3) * 3 + (j / 3);
                //000010000
               if ((row[i] & mask) || (col[j] & mask) || (box[index] & mask)) {
                return false; // duplicate found
            }
                row[i]|=mask;
                col[j]|=mask;
                box[index]|=mask;

            }
        }
        return true;

    }
};