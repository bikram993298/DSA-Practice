class Solution {
public:

    int cnt = 0;

    void solve(TreeNode* root, int mx) {

        if (root == NULL)
            return;

        if (root->val >= mx)
            cnt++;

        mx = max(mx, root->val);

        solve(root->left, mx);
        solve(root->right, mx);
    }

    int goodNodes(TreeNode* root) {

        solve(root, root->val);

        return cnt;
    }
};