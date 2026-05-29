class Solution {
public:

    int ans = 0;

    void solve(TreeNode* root, long long sum,
               int targetSum,
               unordered_map<long long,int>& mp) {

        if(root == NULL)
            return;

        sum += root->val;

        if(mp.find(sum - targetSum) != mp.end()) {
            ans += mp[sum - targetSum];
        }

        mp[sum]++;

        solve(root->left, sum, targetSum, mp);
        solve(root->right, sum, targetSum, mp);

       mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long long,int> mp;

        mp[0] = 1;

        solve(root, 0, targetSum, mp);

        return ans;
    }
};