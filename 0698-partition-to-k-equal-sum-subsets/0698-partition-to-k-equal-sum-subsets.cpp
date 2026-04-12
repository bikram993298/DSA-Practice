class Solution {
public:
    int target;

    bool solve(vector<int>& nums, vector<bool>& used, int k, int currSum, int start) {
        
        // if only one subset left → valid
        if (k == 1) return true;

        // if current subset is complete → move to next subset
        if (currSum == target) {
            return solve(nums, used, k - 1, 0, 0);
        }

        for (int i = start; i < nums.size(); i++) {
            if (used[i] || currSum + nums[i] > target) continue;

            used[i] = true;

            if (solve(nums, used, k, currSum + nums[i], i + 1))
                return true;

            used[i] = false;

            // 🔥 pruning
            if (currSum == 0) return false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        target = sum / k;

        sort(nums.rbegin(), nums.rend()); // important

        vector<bool> used(nums.size(), false);

        return solve(nums, used, k, 0, 0);
    }
};