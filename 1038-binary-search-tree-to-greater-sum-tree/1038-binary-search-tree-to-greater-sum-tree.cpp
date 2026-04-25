class Solution {
public:
    int sum = 0;

    int solve(TreeNode* root) {
        if (root == NULL)
            return sum;

        // Right -> Root -> Left
        solve(root->right);

        sum += root->val;
        root->val = sum;

        solve(root->left);

        return sum;   // return running sum
    }

    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};