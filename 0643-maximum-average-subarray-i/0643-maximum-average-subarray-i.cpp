class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        long long sum = 0;

        int left = 0;

        long long maxSum = LLONG_MIN;

        for(int right = 0; right < n; right++) {

            // include current element
            sum += nums[right];

            // maintain window size k
            if(right - left + 1 > k) {

                sum -= nums[left];

                left++;
            }

            // valid window
            if(right - left + 1 == k) {

                maxSum = max(maxSum, sum);
            }
        }

        return (double)maxSum / k;
    }
};