class Solution {
public:

    int check(TreeNode* root) {

        // Null node height = 0
        if (root == NULL)
            return 0;

        int lh = check(root->left);

        // Left subtree unbalanced
        if (lh == -1)
            return -1;

        int rh = check(root->right);

        // Right subtree unbalanced
        if (rh == -1)
            return -1;

        // Current node unbalanced
        if (abs(lh - rh) > 1)
            return -1;

        // Return height
        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        // in brute froce you can can go right an dleft count height then return bool or not here indeast of bool we are direclty return -1 if not valid it takes complexcity o(n)

        return check(root) != -1;
    }
};