class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                cnt++;


        }else{
            break;
        }
        
    }
    return n-cnt-1;
    }
};