class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                maxi = max(maxi, node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(maxi);
        }

        return result;
    }
};