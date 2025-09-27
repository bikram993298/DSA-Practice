class Solution {
public:
    void twoSum(vector<int>& nums, int k, vector<vector<int>>& result, int target) {
        // Two-pointer technique (Sorted array)
        int i = k, j = nums.size() - 1;
        while(i < j) {
            if(nums[i] + nums[j] > target)
                j--; // Decrease j if the sum is greater than the target
            else if(nums[i] + nums[j] < target)
                i++; // Increase i if the sum is less than the target
            else {
                // If sum equals the target, add the triplet to result
                vector<int> re;
                re.push_back(-target);
                re.push_back(nums[i]);
                re.push_back(nums[j]);
               // result.push_back({-target, nums[i], nums[j]});
               result.push_back(re);
                while(i < j && nums[i] == nums[i+1]) i++; // Skip duplicates for i
                //just think there is 3 same value one you processed then you have to jump 2 more so  so when equla then i increase and at last i also increase for neatral case or default case--just htink without duplicate what you are oding hten with duplicate what you area odung extar rhing must be added
                while(i < j && nums[j] == nums[j-1]) j--; // Skip duplicates for j
                i++; // Move both pointers to continue searching for other pairs
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) // If there are less than 3 numbers, return an empty vector
            return {};
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  // Sort the array to use two-pointer technique

        for(int i = 0; i < nums.size() - 2; i++) {  // Loop through the array
            if(i != 0 && nums[i] == nums[i - 1]) {  // Skip duplicates for the first number
            // if i processed some previous value with smae then continue
                continue;
            }
            // Call twoSum for the rest of the array to find pairs that sum up to -nums[i]
            twoSum(nums, i + 1, result, -nums[i]);
        }

        return result;
    }
};
//muy intituion to solve this we will fix one lement and implement two sum in rest of the array and we have to short this because it will be easy to tackle with duplicate
