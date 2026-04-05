class Solution {
public:
    vector<int> ans;
    int count = 0, maxCount = 0;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Process current node
        if (prev && prev->val == root->val) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        } else if (count == maxCount) {
            ans.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
