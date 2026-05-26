class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> freq;

        long long sum = 0;

        long long ans = 0;

        int left = 0;

        for(int right = 0; right < n; right++) {

            // include current element
            sum += nums[right];

            freq[nums[right]]++;

            // maintain fixed window size
            if(right - left + 1 > k) {

                sum -= nums[left];

                freq[nums[left]]--;

                // completely removed
                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            // valid window
            if(right - left + 1 == k) {

                // all distinct
                if(freq.size() == k) {

                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};