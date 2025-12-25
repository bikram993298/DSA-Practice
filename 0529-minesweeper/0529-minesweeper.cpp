class Solution {
public:
    int dirs[8][2] = {
        {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{1,-1},{-1,1},{-1,-1}
    };
  void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'E')
            return;

        // Count adjacent mines
        int mines = 0;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'M')
                mines++;
        }

        if (mines > 0) {
            board[r][c] = mines + '0';
            return;
        }

        // No adjacent mines
        board[r][c] = 'B';

        // Reveal neighbors
        for (auto &d : dirs) {
            dfs(board, r + d[0], c + d[1]);
        }
  }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        
        // Case 1: Mine clicked
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        // Case 2: Empty cell
        dfs(board, r, c);
        return board;
    }

    
    
};
