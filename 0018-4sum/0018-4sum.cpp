class Solution {
public:
    void twoSum(vector<int>& nums, int k, vector<vector<int>>& result,
                long long target, int first, int second) {
        int i = k, j = nums.size() - 1;
        while (i < j) {
            long long sum = nums[i] + nums[j];
            if (sum > target)
                j--;
            else if (sum < target)
                i++;
            else {

                result.push_back({first, second, nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1])
                    i++;
                while (i < j && nums[j] == nums[j - 1])
                    j--;
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size() - 3; i++) {

            for (int j = i + 1; j < nums.size() - 2; j++) {

                // Call twoSum to find pairs that sum up to target - nums[i] -
                // nums[j]
                long long newTarget =
                    (long long)target - nums[i] - nums[j]; // Prevent overflow
                twoSum(nums, j + 1, result, newTarget, nums[i], nums[j]);

            while(j < n - 3 &&
                    nums[j] ==
                        nums[j + 1]){
                            j++;
                        } // Skip duplicates for the second number
                    
            }

            while (i < n - 4 && nums[i] == nums[i + 1])
                i++;
        }

        return result;
    }
};
