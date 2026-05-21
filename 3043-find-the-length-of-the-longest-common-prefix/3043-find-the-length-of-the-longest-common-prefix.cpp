class Solution {
public:

    struct TrieNode {

        TrieNode* child[10];

        TrieNode() {

            for(int i = 0; i < 10; i++)
                child[i] = NULL;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(int num) {

        string s = to_string(num);

        TrieNode* node = root;

        for(char ch : s) {

            int digit = ch - '0';

            if(node->child[digit] == NULL) {
                node->child[digit] = new TrieNode();
            }

            node = node->child[digit];
        }
    }

    int search(int num) {

        string s = to_string(num);

        TrieNode* node = root;

        int len = 0;

        for(char ch : s) {

            int digit = ch - '0';

            if(node->child[digit] == NULL)
                break;

            node = node->child[digit];

            len++;
        }

        return len;
    }

    int longestCommonPrefix(vector<int>& arr1,
                            vector<int>& arr2) {

        for(int x : arr1)
            insert(x);

        int ans = 0;

        for(int x : arr2) {
            ans = max(ans, search(x));
        }

        return ans;
    }
};