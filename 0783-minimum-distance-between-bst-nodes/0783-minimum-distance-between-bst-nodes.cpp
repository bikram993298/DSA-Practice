class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {

        if (!root)
            return;

        inorder(root->left);

        // process current node
        if (prev != NULL) {
            minDiff = min(minDiff, root->val - prev->val);
        }

        prev = root;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {

        inorder(root);

        return minDiff;
    }
};
