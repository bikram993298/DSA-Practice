class Solution {
public:
    int target;
    int k_;
    int cnt = 0;

    bool solve(vector<int>& nums, vector<bool>& used, int curr, int start) {
        if (cnt == k_) return true;

        if (curr == target) {
            cnt++;
            if (solve(nums, used, 0, 0)) return true;
            cnt--;
            return false;
        }

        for (int i = start; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            if (curr + nums[i] > target) continue;

            used[i] = true;

            if (solve(nums, used, curr + nums[i], i + 1)) return true;

            used[i] = false;
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
        cnt = 0;

        return solve(nums, used, 0, 0);
    }
};