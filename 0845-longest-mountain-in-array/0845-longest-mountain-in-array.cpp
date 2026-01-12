class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int longest = 0;

        // A mountain needs at least 3 elements, so we stop at n-2
        for (int i = 1; i <= n - 2; ++i) {
            
            // Step 1: Identify a peak
            // A peak must be strictly greater than its neighbors
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                
                int left = i - 1;
                int right = i + 1;

                // Step 2: Expand left to find the start of the mountain
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }

                // Step 3: Expand right to find the end of the mountain
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Step 4: Calculate length and update max
                int currentLength = right - left + 1;
                longest = max(longest, currentLength);
                
                // Optimization: Move 'i' to 'right' to skip processed elements
                i = right;
            }
        }

        return longest;
    }
};
//time complexcity o(n) because each elemnt is vsited Although there are nested while loops, the time complexity is $O(N)$ because each element of the array is visited at most three times: once by the main iterator i, once by the left expansion, and once by the right expansion. By updating i to the right boundary of the current mountain, we ensure that we never re-process the same mountain twice. This is an example of linear traversal where the work is spread out across the elements."