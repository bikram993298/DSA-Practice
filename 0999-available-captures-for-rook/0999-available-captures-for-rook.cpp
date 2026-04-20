class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r = -1, c = -1;

        // Step 1: Find rook
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                }
            }
        }

        int ans = 0;

        // 4 directions
        vector<pair<int,int>> dir = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        // Step 2: Explore each direction
        for (auto d : dir) {
            int x = r + d.first;
            int y = c + d.second;

            while (x >= 0 && x < 8 && y >= 0 && y < 8) {

                if (board[x][y] == 'B') break;   // blocked

                if (board[x][y] == 'p') {
                    ans++;       // capture
                    break;
                }

                x += d.first;
                y += d.second;
            }
        }

        return ans;
    }
};