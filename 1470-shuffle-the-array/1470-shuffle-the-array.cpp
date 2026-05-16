class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size=nums.size();
        size=size/2;
        int l=0;
        int r=size;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<2*n;i=i+2){
            ans[i]=nums[l++];
            ans[i+1]=nums[r++];
        }
        
        return ans;
    }
};