class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while (!q.empty()) {
            int n = q.size();
            ans = 0; // reset for current level

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                ans += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};