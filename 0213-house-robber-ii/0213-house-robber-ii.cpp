class Solution {
public:
    int solve(int i, int end, vector<int>& nums, vector<int>& dp) {
        
        // Base case
        if (i > end) return 0;

        // Memoization
        if (dp[i] != -1) return dp[i];

        // Pick current house
        int pick = nums[i] + solve(i + 2, end, nums, dp);

        // Skip current house
        int notPick = solve(i + 1, end, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // If only one house
        if (n == 1) return nums[0];

        /*
            Because houses are circular:
            
            Case 1:
            Take houses from [0 ... n-2]
            (ignore last house)

            Case 2:
            Take houses from [1 ... n-1]
            (ignore first house)

            Answer = max(case1, case2)
        */

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = solve(0, n - 2, nums, dp1);

        int case2 = solve(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};