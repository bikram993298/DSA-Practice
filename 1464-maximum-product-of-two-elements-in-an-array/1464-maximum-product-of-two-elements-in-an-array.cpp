class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        return (nums[0]-1)*(nums[1]-1);
        
    }
};
// in o(n) find first maximum and secind maxmium