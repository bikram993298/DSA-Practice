class Solution {
public:
    int target;
    int k_;

    bool solve(vector<int>& nums, vector<bool>& used, int curr, int start, int cnt) {
        
        if (cnt == k_) return true;

        if (curr == target) {
            return solve(nums, used, 0, 0, cnt + 1);
        }

        for (int i = start; i < nums.size(); i++) {
            if (used[i]) continue;
            if (curr + nums[i] > target) continue;

            used[i] = true;

            if (solve(nums, used, curr + nums[i], i + 1, cnt))
                return true;

            used[i] = false;

            // 🔥 pruning (very important)
            if (curr == 0) return false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        k_ = k;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;

        vector<bool> used(nums.size(), false);

        return solve(nums, used, 0, 0, 0);
    }
};