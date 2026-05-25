// Main Observation

// We are allowed:

// at most k zeroes

// inside our chosen subarray.

// So actual question becomes:

// Find longest subarray containing at most k zeroes.

// THIS is the real transformation.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;

        int zeroCount = 0;

        int maxi = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0) {
                zeroCount++;
            }

            // invalid window
            while (zeroCount > k) {

                if (nums[left] == 0) {
                    zeroCount--;
                }

                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};