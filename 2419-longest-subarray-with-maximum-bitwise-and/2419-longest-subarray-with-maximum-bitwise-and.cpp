class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0, cnt = 0;

        for (int x : nums) {
            if (x == mx) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }

        return ans;
    }
};
// The maximum AND possible from any subarray is simply:

// ➡️ max element in the array

// Because AND of multiple numbers can never exceed any individual number.

// So we just need the longest consecutive streak of elements equal to the maximum value.