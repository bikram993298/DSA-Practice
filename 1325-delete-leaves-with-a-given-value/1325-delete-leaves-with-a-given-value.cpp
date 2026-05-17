class Solution {
public:

    void solve(TreeNode* &root, int target) {

        // if (!root)
        //     return;
//post order
        if (root->left)
            solve(root->left, target);

        if (root->right)
            solve(root->right, target);

        // delete if it became leaf
        if (!root->left && !root->right && root->val == target) {
            root = NULL;
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        solve(root, target);

        return root;
    }
};