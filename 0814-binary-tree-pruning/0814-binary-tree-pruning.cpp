class Solution {
public:

    int solve(TreeNode* root) {
        if (!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        // prune left
        if (left == 0) root->left = NULL;

        // prune right
        if (right == 0) root->right = NULL;

        // total number of 1s in subtree
        return left + right + (root->val == 1);
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (solve(root) == 0) return NULL;
        return root;
    }
};