class Solution {
public:
    int findMin(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            // remove duplicates from left
            while (start < end &&
                   nums[start] == nums[start + 1]) {

                start++;
            }

            // remove duplicates from right
            while (start < end &&
                   nums[end] == nums[end - 1]) {

                end--;
            }

            int mid = start + (end - start) / 2;

            // minimum lies on right side
            if (nums[end] < nums[mid]) {
                start = mid + 1;
            }

            // minimum lies on left including mid
            else {
                end = mid;
            }
        }

        return nums[end];
    }
};