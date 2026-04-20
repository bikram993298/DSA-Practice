class Solution {
public:
    TreeNode* parentX = NULL;
    TreeNode* parentY = NULL;
    int depthX = -1;
    int depthY = -1;

    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y) {
        if (!root) return;

        // your required code start from here

        if (root->val == x) {
            parentX = parent;
            depthX = depth;
        }

        if (root->val == y) {
            parentY = parent;
            depthY = depth;
        }

        // your required code end here

        dfs(root->left, root, depth + 1, x, y);
        dfs(root->right, root, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, 0, x, y);

        return (depthX == depthY) && (parentX != parentY);
    }
};