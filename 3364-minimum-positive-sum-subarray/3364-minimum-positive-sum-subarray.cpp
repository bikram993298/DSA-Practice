class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        
        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        
        multiset<long long> window;
        long long ans = LLONG_MAX;
        
        for(int j = 1; j <= n; j++) {
            
            // Add prefix[j - l] to window
            if(j - l >= 0)
                window.insert(prefix[j - l]);
            
            // Remove prefix[j - r - 1]
            if(j - r - 1 >= 0)
                window.erase(window.find(prefix[j - r - 1]));
            
            if(!window.empty()) {
                auto it = window.lower_bound(prefix[j]);
                
                if(it != window.begin()) {
                    --it; // largest prefix[i] < prefix[j]
                    long long sum = prefix[j] - *it;
                    if(sum > 0)
                        ans = min(ans, sum);
                }
            }
        }
        
        return ans == LLONG_MAX ? -1 : ans;
    }
};