class Solution {
public:
    long long ans = 0;

    vector<long long> dfs(TreeNode* root) {

        // {min, max, sum}
        if (!root)
            return {(long long)INT_MAX, (long long)INT_MIN, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Check BST condition
        if (root->val > left[1] && root->val < right[0]) {

            long long currsum = left[2] + right[2] + root->val;

            ans = max(ans, currsum);

            long long minval = min((long long)root->val, left[0]);
            long long maxval = max((long long)root->val, right[1]);

            return {minval, maxval, currsum};
        }

        // Not BST
        long long maxsum = max(left[2], right[2]);
        return {(long long)INT_MIN, (long long)INT_MAX, maxsum};
    }

    int maxSumBST(TreeNode* root) {

        ans = 0;
        dfs(root);

        return ans;
    }
};
