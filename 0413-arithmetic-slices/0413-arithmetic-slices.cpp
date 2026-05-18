// class Solution {
// public:

//     vector<int> dp;

//     int solve(int i, vector<int>& nums) {

//         // need at least 3 elements
//         if(i < 2)
//             return 0;

//         // already computed
//         if(dp[i] != -1)
//             return dp[i];

//         int currDiff = nums[i] - nums[i-1];
//         int prevDiff = nums[i-1] - nums[i-2];

//         // arithmetic
//         if(currDiff == prevDiff) {

//             return dp[i] = solve(i-1, nums) + 1;
//         }

//         // not arithmetic
//         return dp[i] = 0;
//     }

//     int numberOfArithmeticSlices(vector<int>& nums) {

//         int n = nums.size();

//         dp.assign(n, -1);

//         int ans = 0;

//         for(int i = 2; i < n; i++) {

//             ans += solve(i, nums);
//         }

//         return ans;
//     }
// };



class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();

        if(n < 3)
            return 0;

        // dp[i] = number of arithmetic slices
        // ending at index i
        vector<int> dp(n, 0);

        int ans = 0;

        for(int i = 2; i < n; i++) {

            int d1 = nums[i] - nums[i - 1];
            int d2 = nums[i - 1] - nums[i - 2];

            // arithmetic continues
            if(d1 == d2) {

                dp[i] = dp[i - 1] + 1;

                ans += dp[i];
            }
        }

        return ans;
    }
};