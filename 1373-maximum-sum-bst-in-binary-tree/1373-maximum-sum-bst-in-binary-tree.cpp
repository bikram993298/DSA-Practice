class Solution {
public:

    long long ans = 0;

    bool dfs(TreeNode* root,
             long long &sum,
             int &mini,
             int &maxi) {

        if (!root) {
            sum = 0;
            mini = INT_MAX;
            maxi = INT_MIN;
            return true;
        }

        long long lsum, rsum;
        int lmin, lmax, rmin, rmax;

        bool lb = dfs(root->left, lsum, lmin, lmax);
        bool rb = dfs(root->right, rsum, rmin, rmax);

        if (lb && rb && lmax < root->val && root->val < rmin) {

            sum = lsum + rsum + root->val;
            mini = min(root->val, lmin);
            maxi = max(root->val, rmax);

            ans = max(ans, sum);

            return true;
        }

        return false;
    }

    int maxSumBST(TreeNode* root) {

        long long sum;
        int mini, maxi;

        dfs(root, sum, mini, maxi);

        return ans;
    }
};
