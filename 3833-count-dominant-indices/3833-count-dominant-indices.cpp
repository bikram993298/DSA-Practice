class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n=nums.size();
        vector<int> suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];

        }
        // 12  7 3
         int ans=0;
         for(int i=0;i<n-1;i++){
            if(nums[i]>(double)(suffix[i]-nums[i])/(n-i-1)){
            cout<<(double)(suffix[i]-nums[i])/(n-i-1)<<endl;
               ans++;

            }
         }

        return ans;
    }
};