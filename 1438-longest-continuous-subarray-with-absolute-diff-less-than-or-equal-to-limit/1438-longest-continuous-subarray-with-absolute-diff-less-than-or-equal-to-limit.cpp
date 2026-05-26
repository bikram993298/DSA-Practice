// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

// We need:

// longest subarray such that:

// max(nums)−min(nums)≤limit


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> maxDeque;
        deque<int> minDeque;

        int left = 0;

        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            // maintain decreasing deque for maximum
            while(!maxDeque.empty() &&
                  maxDeque.back() < nums[right]) {

                maxDeque.pop_back();
            }

            maxDeque.push_back(nums[right]);

            // maintain increasing deque for minimum
            while(!minDeque.empty() &&
                  minDeque.back() > nums[right]) {

                minDeque.pop_back();
            }

            minDeque.push_back(nums[right]);

            // invalid window
            while(maxDeque.front() - minDeque.front() > limit) {

                // remove expired max
                if(nums[left] == maxDeque.front()) {
                    maxDeque.pop_front();
                }

                // remove expired min
                if(nums[left] == minDeque.front()) {
                    minDeque.pop_front();
                }

                left++;
            }

            // valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};