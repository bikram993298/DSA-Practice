// class Solution {
// public:
//     string longestWord(vector<string>& words) {
//         sort(words.begin(), words.end());

//         unordered_set<string> st;
//         string ans = "";

//         for (auto &word : words) {
//             // if single char OR prefix exists
//             if (word.size() == 1 || st.count(word.substr(0, word.size() - 1))) {
//                 st.insert(word);

//                 if (word.size() > ans.size()) {
//                     ans = word;
//                 }
//             }
//         }

//         return ans;
//     }
// };
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    string ans = "";

    void insert(TrieNode* root, string &word) {
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

    void dfs(TrieNode* node, string curr) {
        // update answer
        if (curr.size() > ans.size() || 
           (curr.size() == ans.size() && curr < ans)) {
            ans = curr;
        }

        for (int i = 0; i < 26; i++) {
            TrieNode* child = node->children[i];

            // only go if prefix is valid word
            if (child && child->isEnd) {
                dfs(child, curr + char('a' + i));
            }
        }
    }

    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();

        // insert all words
        for (auto &word : words) {
            insert(root, word);
        }

        // start DFS
        dfs(root, "");

        return ans;
    }
};