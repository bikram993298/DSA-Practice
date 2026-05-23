class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // both in left subtree
        if (p->val < root->val && q->val < root->val) {

            return lowestCommonAncestor(root->left, p, q);
        }

        // both in right subtree
        if (p->val > root->val && q->val > root->val) {

            return lowestCommonAncestor(root->right, p, q);
        }

        // split happens here
        return root;
    }
};