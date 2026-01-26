class Solution {
public:
    bool check(int x) {
        int b = sqrt(x);
        return b * b == x;
    }

    int solve(int i, vector<int>& nums, vector<bool>& used, int prev) {
        int n = nums.size();
        if (i == n) return 1;

        int ans = 0;

        for (int j = 0; j < n; j++) {
            if (used[j]) continue;

            // skip duplicates
            if (j > 0 && nums[j] == nums[j - 1] && !used[j - 1]) continue;

            if (prev == -1 || check(nums[j] + prev)) {
                used[j] = true;
                ans += solve(i + 1, nums, used, nums[j]);
                used[j] = false;
            }
        }

        return ans;
    }

    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> used(n, false);

        return solve(0, nums, used, -1);
    }
};
