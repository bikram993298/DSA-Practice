class Solution {
public:
    vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string& word) {
        // you habe to remeber how in grid backtracking works
        if(idx == word.size()) return true;
        
        int n = board.size(), m = board[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        // making because of viited then going to neighbour
        // this for loop ending means you hae gone thorugh all direction after that you are getinng nohting in psitive return menas false ,
        for(auto d : moves) {
            int ni = i + d.first;
            int nj = j + d.second;
            
            if(dfs(ni, nj, idx+1, board, word))
                return true;
        }
        // undo the wrokings ten return falsse; because yo g=hae nto got any succes ful
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, 0, board, word))
                    return true;
            }
        }
        
        return false;
    }
};