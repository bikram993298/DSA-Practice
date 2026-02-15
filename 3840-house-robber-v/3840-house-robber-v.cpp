class Solution {
public:
  vector<long long>dp;

   long long solve(int i,vector<int>& nums,vector<int>& colors){
    int n=nums.size();

    // base case
    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];
    //rob
    long long rob=0;
    if(i==n-1){
        rob=nums[i]+solve(i+1,nums,colors);
    }
    else if(( (colors[i]==colors[i+1]) ) ){
          rob=nums[i]+solve(i+2,nums,colors);

    }else{
        rob=nums[i]+solve(i+1,nums,colors);

    }
    
   

    //not rob
    long long notrob=solve(i+1,nums,colors);




    return dp[i]=max(rob,notrob);








   }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        // int co=colors.size();
        dp.resize(n,-1);
        long long ans=solve(0,nums,colors);

         return ans;
    }
};