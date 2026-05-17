class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int n = arr.size();
        // the question actaully find number of subarry ehwere sum is k*
        // thresold and sizek

        int target = k * threshold;

        int sum = 0;

        // first window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int count = 0;

        if (sum >= target)
            count++;

        // sliding window
        for (int i = k; i < n; i++) {

            sum += arr[i];
            sum -= arr[i - k];

            if (sum >= target)
                count++;
        }

        return count;
    }
};