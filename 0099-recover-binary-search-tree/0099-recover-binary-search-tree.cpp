class Solution {
public:
    TreeNode* wrong1 = NULL;
    TreeNode* wrong2 = NULL;

    void inorder(TreeNode* root, TreeNode*& prev) {
        if (!root)
            return;

        inorder(root->left, prev);

        if (prev && prev->val > root->val) {

            if (!wrong1)
                wrong1 = prev;

            wrong2 = root;
        }

        prev = root;

        inorder(root->right, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;

        inorder(root, prev);

        swap(wrong1->val, wrong2->val);
    }
};

// in sotered     1 2 3 4 5
// after msimathc 1 5 3 4 2
// so during inorder traversal left part is done first so in current session preform all things then when you go to next make prev root because you have to tack this 