class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        
        int currMax = nums[0];
        int currMin = nums[0];
        
        for (int i = 1; i < n; i++) {
            int prevMax = currMax;
            int prevMin = currMin;
            // used idf not used currmax updates then this updat changes in currmin that should not be thhere
            
            currMax = max({nums[i], nums[i] * prevMax, nums[i] * prevMin});
            currMin = min({nums[i], nums[i] * prevMax, nums[i] * prevMin});
            
            ans = max(ans, currMax);
        }
        
        return ans;
    }
};
