class Solution {
public:
    string ans = "~"; // bigger than any lowercase string

    void dfs(TreeNode* root, string path) {
        if (!root) return;

        // convert number to character
        char ch = 'a' + root->val;

        // build string from leaf → root
        //add char to front beCAE leaf to node
        path = ch + path;

       

        // if leaf node → compare with answer
        if (!root->left && !root->right) {
            // compare with empty string
            if (path < ans) {
                ans = path;
            }
        }

       

        dfs(root->left, path);
        dfs(root->right, path);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};