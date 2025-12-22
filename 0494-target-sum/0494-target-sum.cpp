class Solution {
public:
    int solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(i==0){  
            if(target==0 && nums[0]==0) return 2; // +0 or -0
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        
        if(nums[i]<=target){
            return dp[i][target] = solve(i-1,target-nums[i],nums,dp) 
                                 + solve(i-1,target,nums,dp);
        } else {
            return dp[i][target] = solve(i-1,target,nums,dp);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if((sum+target)%2 != 0 || abs(target) > sum) return 0;

        int n = nums.size();
        int subsetSum = (sum+target)/2;

        vector<vector<int>> dp(n,vector<int>(subsetSum+1,-1));
        return solve(n-1,subsetSum,nums,dp);
    }
};
