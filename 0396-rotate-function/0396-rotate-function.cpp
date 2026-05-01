class Solution {
public:
    int ans;
    int base_sum=0;
    int sum=0;
    int max_sum=0;
    int n;
    int solve(int k,vector<int> &  nums){
   if(k==0){
    return base_sum;
           
   }
   int ree=solve(k-1,nums)+sum-n*nums[n-k];
   max_sum=max(max_sum,ree);


   return ree;


    }
    int maxRotateFunction(vector<int>& nums) {
        n=nums.size();


        for(int i=0;i<n;i++){
            base_sum+=(i*nums[i]);
            sum+=nums[i];
        }
        max_sum=base_sum;
      int ans1=  solve(n-1,nums);
        return max_sum;

        

        
    }
};