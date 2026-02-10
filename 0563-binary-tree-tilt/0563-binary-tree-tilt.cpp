class Solution {
public:
    int totalTilt = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        totalTilt += abs(leftSum - rightSum);

        return leftSum + rightSum + root->val;
    }

    int findTilt(TreeNode* root) {
        dfs(root);
        return totalTilt;
    }
};
