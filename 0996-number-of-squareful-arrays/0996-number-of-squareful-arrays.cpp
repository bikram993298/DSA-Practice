class Solution {
public:
    bool check(int i){
        int b=sqrt(i);
        return b*b==i;
    }
    int solve(int i,vector<int> & nums,vector<bool>& used,int prev){
        int n=nums.size();
        if(i==n){
            return 1;

        }
        int ans=0;
    
    for(int j=0;j<n;j++){
        if(used[j])continue;
         if (j> 0 && nums[j] == nums[j - 1] && !used[j - 1]) continue;
       if(prev == -1 || check(nums[j] + prev))
{
            used[j] = true;


            ans=ans+solve(i+1,nums,used,nums[j]);
           used[j] = false;


        }
    }

    return ans;
        
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<bool> used(n,false);
        int ans=solve(0,nums,used,-1);
        return ans;
        
    }
};