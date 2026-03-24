class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip used numbers
            if (used[i]) continue;

            // Skip duplicates at the same recursion depth
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, curr, used);
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Ensure duplicates are adjacent
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr, used);
        return res;
    }
};
