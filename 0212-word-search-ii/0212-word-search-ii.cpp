class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        word = "";
    }
};

class Solution {
public:
    void insert(TrieNode* root, string& word) {

        TrieNode* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->children[idx] == NULL) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(int i, int j, vector<vector<char>>& board, TrieNode* node,
             vector<string>& ans) {

        char ch = board[i][j];

        // prefix does not exist
        if (node->children[ch - 'a'] == NULL) {
            return;
        }

        node = node->children[ch - 'a'];
           // mark visited
        board[i][j] = '#';

        // word found
        if (node->word != "") {

            ans.push_back(node->word);
            // like you have got string bikram then if  somehow you got another root that givinf same for that remove string word from tree by making blank
            // avoid duplicate insertion
            node->word = "";
        }

     

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& d : dirs) {

            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < board.size() &&
                nj < board[0].size() && board[ni][nj] != '#') {

                dfs(ni, nj, board, node, ans);
            }
        }

        // backtrack
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        // build trie
        for (string& word : words) {
            insert(root, word);
        }

        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                dfs(i, j, board, root, ans);
            }
        }

        return ans;
    }
};