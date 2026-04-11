// class MagicDictionary {
// public:
//     vector<string> dict;

//     MagicDictionary() {}

//     void buildDict(vector<string> dictionary) {
//         dict = dictionary;
//         //o(n)
//     }

//     bool search(string word) {
//         for (string &s : dict) {
//             if (s.size() != word.size()) continue;

//             int diff = 0;
//             for (int i = 0; i < s.size(); i++) {
//                 if (s[i] != word[i]) diff++;
//                 if (diff > 1) break;
//             }
// //o(n *m)
//             if (diff == 1) return true;
//         }
//         return false;
//     }
// };
class MagicDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) children[i] = NULL;
        }
    };

    TrieNode* root;

    MagicDictionary() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    void buildDict(vector<string> dictionary) {
        for (auto &word : dictionary) {
            insert(word);
            //o(n*m)
        }
    }

    bool dfs(string &word, int i, TrieNode* node, bool usedChange) {
        if (!node) return false;

        if (i == word.size()) {
            return usedChange && node->isEnd;
        }

        int idx = word[i] - 'a';

        // Case 1: no change
        if (node->children[idx]) {
            if (dfs(word, i + 1, node->children[idx], usedChange))
                return true;
        }

        // Case 2: try change
        if (!usedChange) {
            for (int c = 0; c < 26; c++) {
                if (c != idx && node->children[c]) {
                    if (dfs(word, i + 1, node->children[c], true))
                        return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return dfs(word, 0, root, false);
       // o(m*26)
    }
};