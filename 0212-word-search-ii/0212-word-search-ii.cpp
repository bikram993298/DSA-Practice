class TrieNode {
public:
    TrieNode* children[26];
    string word;  // stores word if this node is end

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
        word = "";
    }
};

class Solution {
public:
    vector<string> result;

    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->word = word;  // mark end
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];

        // Not in Trie
        if (c == '#' || node->children[c - 'a'] == NULL)
            return;

        node = node->children[c - 'a'];

        // Found word
        if (node->word != "") {
            result.push_back(node->word);
            node->word = "";  // avoid duplicates
        }

        // Mark visited
        board[i][j] = '#';
        //you are using this as visisted so in next call there boar i j, can be # thhis if this check return ,,,

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size()) {
                dfs(board, ni, nj, node);
            }
        }

        // Backtrack
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode* root = new TrieNode();

        // Build Trie
        for (string& word : words) {
            insert(root, word);
        }

        // Start DFS from every cell
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};
//o(m*n*4^l)