class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // rows
        for(int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c == '.') continue;
                if(st.count(c)) return false;
                st.insert(c);
            }
        }
        
        // columns
        for(int j = 0; j < 9; j++) {
            unordered_set<char> st;
            for(int i = 0; i < 9; i++) {
                char c = board[i][j];
                if(c == '.') continue;
                if(st.count(c)) return false;
                st.insert(c);
            }
        }
        
        // 3x3 boxes
        for(int sr = 0; sr < 9; sr += 3) {
            for(int sc = 0; sc < 9; sc += 3) {
                
                unordered_set<char> st;
                
                for(int i = sr; i < sr + 3; i++) {
                    for(int j = sc; j < sc + 3; j++) {
                        char c = board[i][j];
                        if(c == '.') continue;
                        if(st.count(c)) return false;
                        st.insert(c);
                    }
                }
            }
        }
        
        return true;
    }
};