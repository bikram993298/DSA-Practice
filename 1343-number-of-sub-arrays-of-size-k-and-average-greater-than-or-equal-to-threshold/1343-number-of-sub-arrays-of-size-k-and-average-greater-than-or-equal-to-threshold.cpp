class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int n = arr.size();

        int target = threshold * k;

        int sum = 0;

        int left = 0;

        int count = 0;

        for(int right = 0; right < n; right++) {

            // include current element
            sum += arr[right];

            // maintain window size k
            if(right - left + 1 > k) {

                sum -= arr[left];

                left++;
            }

            // valid window
            if(right - left + 1 == k) {

                if(sum >= target) {
                    count++;
                }
            }
        }

        return count;
    }
};