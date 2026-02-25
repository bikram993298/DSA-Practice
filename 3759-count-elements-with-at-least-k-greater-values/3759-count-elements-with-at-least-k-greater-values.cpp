class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> cnt(n);
// 1 1 1 1 2 3
     map<int,int>mp;
        for(int i=0;i<n;i++){
            //  if(i>0 && nums[i]==nums[i-1]){
            //     continue;
            // }
            mp[nums[i]]=n-i-1;
           
        }
        //1->2
        //2 1
        // 3 0
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]>=k) ans++;
        }


        return ans;
    }
};