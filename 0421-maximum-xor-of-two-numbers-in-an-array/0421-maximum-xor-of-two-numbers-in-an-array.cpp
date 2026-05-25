class TrieNode {
public:
    TrieNode* children[2];

    TrieNode() {

        children[0] = NULL;
        children[1] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(int num) {

        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (node->children[bit] == NULL) {

                node->children[bit] = new TrieNode();
            }

            node = node->children[bit];
        }
    }

    int getMaxXor(int num) {

        TrieNode* node = root;

        int ans = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            int opposite = 1 - bit;

            // prefer opposite bit
            if (node->children[opposite] != NULL) {

                ans |= (1 << i);

                node = node->children[opposite];
            } else {

                node = node->children[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        // insert all numbers
        for (int num : nums) {

            trie.insert(num);
        }

        int maxi = 0;

        for (int num : nums) {

            maxi = max(maxi, trie.getMaxXor(num));
        }

        return maxi;
    }
};