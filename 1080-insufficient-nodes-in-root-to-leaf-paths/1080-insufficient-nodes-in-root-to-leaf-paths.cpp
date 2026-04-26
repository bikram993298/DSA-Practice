class Solution {
public:

    bool solve(TreeNode* root, int limit) {
        if (root == NULL) {
            return false;
        }

        // leaf node
        if (root->left == NULL && root->right == NULL) {
            // true means this path is sufficient
            return root->val >= limit;
        }

        // check left and right subtree
        bool leftValid = solve(root->left, limit - root->val);
        bool rightValid = solve(root->right, limit - root->val);

        // if left path is insufficient, delete left child
        if (!leftValid) {
            root->left = NULL;
        }

        // if right path is insufficient, delete right child
        if (!rightValid) {
            root->right = NULL;
        }

        // current node is sufficient
        // if at least one child path is valid
        return leftValid || rightValid;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        // if root itself becomes insufficient
        if (!solve(root, limit)) {
            return NULL;
        }

        return root;
    }
};