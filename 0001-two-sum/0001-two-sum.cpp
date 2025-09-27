class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;  // To store number and its index
        vector<int> ans;

        // Store all elements and their indices in the map
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        // Find the two indices
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // Check if complement exists and is not the same index
            if (mp.find(complement) != mp.end() && mp[complement] != i) {
                ans.push_back(i);
                ans.push_back(mp[complement]);
                break;  // Return immediately after finding the pair
            }
        }

        return ans;
    }
};
