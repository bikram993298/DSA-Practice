class Solution {
public:
    unordered_map<int, int> freq;
    int maxFreq = 0;

    int dfs(TreeNode* root) {

        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int sum = root->val + left + right;

        freq[sum]++;

        maxFreq = max(maxFreq, freq[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {

        dfs(root);

        vector<int> result;

        for (auto it : freq) {
            if (it.second == maxFreq)
                result.push_back(it.first);
        }

        return result;
    }
};
