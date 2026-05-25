class Trie {
public:
   struct TrieNode {
        TrieNode* child[26];
        bool isend;

        TrieNode() {
            isend = false;

            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* current = root;
        for (auto it : word) {
            int index = it - 'a';
            if(current->child[index] == nullptr) {
                current->child[index] = new TrieNode();
            }

            current = current->child[index];
        }

        current->isend = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (auto it : word) {
            int index = it - 'a';

            if (current->child[index] == NULL) {
                return false;
            }
            current = current->child[index];
        }

        return current->isend;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (char character : prefix) {
            int index = character - 'a';

            if (current->child[index] == nullptr)
                return false;

            current = current->child[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */