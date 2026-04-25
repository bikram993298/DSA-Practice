class Solution {
public:

    int helper(vector<int>& nums, int L, int M) {
        int n = nums.size();

        // 1-based prefix sum
        // prefix[i] = sum of first i elements
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        vector<int> left(n + 1, 0);
        vector<int> right(n + 2, 0);

        // left[i] = best L-length subarray till index i

        for (int i = L; i <= n; i++) {
            int sum = prefix[i] - prefix[i - L];
            left[i] = max(left[i - 1], sum);
        }

        // right[i] = best M-length subarray from i to n

        for (int i = n - M + 1; i >= 1; i--) {
            int sum = prefix[i + M - 1] - prefix[i - 1];
            right[i] = max(right[i + 1], sum);
        }

        int ans = 0;

        // split point
        for (int i = L; i <= n - M; i++) {
            ans = max(ans, left[i] + right[i + 1]);
        }

        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        return max(
            helper(nums, firstLen, secondLen),
            helper(nums, secondLen, firstLen)
        );
    }
};