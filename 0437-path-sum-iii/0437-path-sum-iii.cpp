class Solution {
public:
    unordered_map<long long, int> mp;
    int cnt = 0;

    void dfs(TreeNode* root, long long sum, int target) {
        if (!root) return;

        sum += root->val;

        if (sum == target)
            cnt++;

        if (mp.count(sum - target))
            cnt += mp[sum - target];

        mp[sum]++;
        dfs(root->left, sum, target);
        dfs(root->right, sum, target);
        mp[sum]--;   // backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return cnt;
    }
};
