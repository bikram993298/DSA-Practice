class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int swappedPrev, vector<int>& nums1, vector<int>& nums2) {
        
        if (i == n) return 0;

        if (dp[i][swappedPrev] != -1) return dp[i][swappedPrev];

        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];

        // If previous was swapped, reverse them
        if (swappedPrev) {
            swap(prev1, prev2);
        }

        int ans = INT_MAX;

        // 🔹 Option 1: No swap
        if (nums1[i] > prev1 && nums2[i] > prev2) {
            ans =min(ans, solve(i+1, 0, nums1, nums2));
        }

        // 🔹 Option 2: Swap
        if (nums1[i] > prev2 && nums2[i] > prev1) {
            ans = min(ans, 1 + solve(i+1, 1, nums1, nums2));
        }

        return dp[i][swappedPrev] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp.assign(n, vector<int>(2, -1));

        // Try both starting possibilities
        return min(
            solve(1, 0, nums1, nums2),        // no swap at 0
            1 + solve(1, 1, nums1, nums2)     // swap at 0
        );
    }
};