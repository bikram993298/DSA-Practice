// MOST IMPORTANT FORMULA
// exact(k)=atMost(k)−atMost(k−1)

// Very famous sliding window trick.

// Why Sliding Window Works

// Because:

// array has non-negative numbers only
// sum increases monotonically

// So:

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {

        if (goal < 0) {
            return 0;
        }

        int left = 0;

        int sum = 0;

        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (sum > goal) {

                sum -= nums[left];

                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};