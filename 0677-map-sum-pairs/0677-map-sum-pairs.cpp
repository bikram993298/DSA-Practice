class MapSum {
public:
    struct TrieNode {
        TrieNode* children[26];
        int sum;

        TrieNode() {
            sum = 0;
            for (int i = 0; i < 26; i++) children[i] = NULL;
        }
    };

    TrieNode* root;
    unordered_map<string, int> mp;

    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        // for update like apple 5
        // apple 3 then you have to 3-5=-2 plus in the update of all node al
        int diff = val - mp[key];  // handle update
        mp[key] = val;

        TrieNode* node = root;
        for (char c : key) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->sum += diff;
        }
    }
    
    int sum(string prefix) {
        TrieNode* node = root;

        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return 0;
            node = node->children[idx];
        }

        return node->sum;
    }
};