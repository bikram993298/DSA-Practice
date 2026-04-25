class Solution {
public:

    int helper(vector<int>& nums, int L, int M) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // left[i] = best L-length subarray till i
        int sum = prefix[L] - prefix[0];
        left[L - 1] = sum;

        for (int i = L; i < n; i++) {
            sum = prefix[i + 1] - prefix[i + 1 - L];
            left[i] = max(left[i - 1], sum);
        }

        // right[i] = best M-length subarray from i to end
        sum = prefix[n] - prefix[n - M];
        right[n - M] = sum;

        for (int i = n - M - 1; i >= 0; i--) {
            sum = prefix[i + M] - prefix[i];
            right[i] = max(right[i + 1], sum);
        }

        int ans = 0;

        for (int i = L - 1; i < n - M; i++) {
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