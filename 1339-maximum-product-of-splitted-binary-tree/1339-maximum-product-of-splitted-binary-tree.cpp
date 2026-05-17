class Solution {
public:

    long long total = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    // total tree sum
    long long findTotal(TreeNode* root) {

        if (!root)
            return 0;

        return root->val +
               findTotal(root->left) +
               findTotal(root->right);
    }

    long long solve(TreeNode* root) {

        if (!root)
            return 0;
//post order bacuse atfirst edge then if condition then
        long long left = solve(root->left);
        long long right = solve(root->right);

        long long currSum = root->val + left + right;

        ans = max(ans, currSum * (total - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {

        total = findTotal(root);

        solve(root);

        return ans % MOD;
    }
};