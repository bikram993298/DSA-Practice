class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == nums1.size() || j == nums2.size())
            return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, nums1, nums2);
        }

        return dp[i][j] = 0;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, nums1, nums2));
            }
        }

        return ans;
    }
};