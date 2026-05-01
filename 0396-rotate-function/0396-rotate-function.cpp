class Solution {
public:
    long long base_sum = 0;
    long long sum = 0;
    long long max_sum;
    int n;

    long long solve(int k, vector<int> &nums) {
        if (k == 0) {
            return base_sum;
        }

        long long prev = solve(k - 1, nums);

        long long curr = prev + sum - (long long)n * nums[n - k];

        max_sum = max(max_sum, curr);

        return curr;
    }

    int maxRotateFunction(vector<int>& nums) {
        n = nums.size();

        base_sum = 0;
        sum = 0;

        for (int i = 0; i < n; i++) {
            base_sum += (long long)i * nums[i];
            sum += nums[i];
        }

        max_sum = base_sum; // include F(0)

        solve(n - 1, nums);

        return (int)max_sum;
    }
};