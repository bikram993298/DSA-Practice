class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> prefix(n + 1, 0), suffix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] | nums[i];
        }

        
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }

        long long ans = 0;
        long long shiftVal = 1LL << k;

        for (int i = 0; i < n; i++) {
            long long cur = prefix[i] | (nums[i] * shiftVal) | suffix[i + 1];
            ans = max(ans, cur);
        }

        return ans;
    }
};
//main concpeti is you can multiply by 2 any time , you have to make maximum so if u make left shift of same number k times it  will be set1 to moreleft instead of differernt number so left shift thne check alll