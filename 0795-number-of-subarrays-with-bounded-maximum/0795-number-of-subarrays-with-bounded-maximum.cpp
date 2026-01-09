class Solution {
public:
    int countBounded(vector<int>& nums, int bound) {
        int count = 0;
        int len = 0;

        for (int x : nums) {
            if (x <= bound) {
                len++;
            } else {
                len = 0;
            }
            count += len;
        }
        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countBounded(nums, right) -
               countBounded(nums, left - 1);
    }
};
