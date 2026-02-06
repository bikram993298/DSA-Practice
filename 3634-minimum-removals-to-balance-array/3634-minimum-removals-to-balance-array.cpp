class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int ans=INT_MAX;
           int n=nums.size();
        for (int i = 0; i <nums.size(); i++) {
            long long limit = (long long)nums[i] * k;
            int idx =
                upper_bound(nums.begin(), nums.end(), limit) - nums.begin();
            int len = idx - i;
            ans = min(ans, n - len);
        }

        return ans;
    }
};