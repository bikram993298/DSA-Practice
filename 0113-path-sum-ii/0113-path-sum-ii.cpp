class Solution {
public:

    vector<vector<int>> ans;

    void solve(TreeNode* root, int sum,
               int targetSum, vector<int>& path) {

        if(root == NULL)
            return;

        sum += root->val;

        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {

            if(sum == targetSum) {
                ans.push_back(path);
            }
        }

        solve(root->left, sum, targetSum, path);
        solve(root->right, sum, targetSum, path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> path;

        solve(root, 0, targetSum, path);

        return ans;
    }
};