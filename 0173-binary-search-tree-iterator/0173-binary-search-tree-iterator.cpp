class BSTIterator {
private:
    vector<int> inorder;
    int index = 0;

    void traverse(TreeNode* root) {
        if (!root) return;

        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        traverse(root);
    }

    int next() {
        return inorder[index++];
    }

    bool hasNext() {
        return index < inorder.size();
    }
};