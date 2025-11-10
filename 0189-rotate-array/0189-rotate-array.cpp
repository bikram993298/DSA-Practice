class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> array(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            array[(i + k) % nums.size()] = nums[i];
        }
        nums = array; 
    }
};
