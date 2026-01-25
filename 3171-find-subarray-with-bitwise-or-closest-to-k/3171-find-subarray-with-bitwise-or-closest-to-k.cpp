class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bit(32, 0);

        auto add = [&](int x) {
            for (int b = 0; b < 32; b++) {
                if (x & (1 << b)) bit[b]++;
            }
        };

        auto remove = [&](int x) {
            for (int b = 0; b < 32; b++) {
                if (x & (1 << b)) bit[b]--;
            }
        };

        auto getOR = [&]() {
            int val = 0;
            for (int b = 0; b < 32; b++) {
                if (bit[b] > 0) val |= (1 << b);
            }
            return val;
        };

        int ans = INT_MAX;
        int l = 0;

        for (int r = 0; r < n; r++) {
            add(nums[r]);

            while (l <= r) {
                int curOR = getOR();
                ans = min(ans, abs(curOR - k));
                if (ans == 0) return 0;

                // shrink only when OR >= k (try to get closer)
                if (curOR >= k) {
                    remove(nums[l]);
                    l++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};
