class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        return atLeastK(nums, k) - atLeastK(nums, k + 1);
    }

    long long atLeastK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bit(32, 0);
        long long ans = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {

            // add nums[r] into window
            add(bit, nums[r]);

            // shrink window until AND >= k
            while (l <= r && getAND(bit, r - l + 1) < k) {
                remove(bit, nums[l]);
                l++;
            }

            // all subarrays ending at r and starting from l..r are valid
            ans += (r - l + 1);
        }
        return ans;
    }

    void add(vector<int>& bit, int x) {
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i)) bit[i]++;
        }
    }

    void remove(vector<int>& bit, int x) {
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i)) bit[i]--;
        }
    }

    int getAND(vector<int>& bit, int len) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bit[i] == len) res |= (1 << i);  // bit must be present in all elements
        }
        return res;
    }
};
