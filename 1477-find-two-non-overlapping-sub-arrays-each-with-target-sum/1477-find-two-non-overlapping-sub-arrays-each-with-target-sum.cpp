class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        vector<int> best(n, INT_MAX);
        
        int sum = 0;
        int res = INT_MAX;
        int minLen = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(mp.count(sum - target)) {
                int start = mp[sum - target];
                int len = i - start;
                
                // combine with previous best
                if(start >= 0 && best[start] != INT_MAX) {
                    res = min(res, len + best[start]);
                }
                
                // update current best
                minLen = min(minLen, len);
            }
            
            best[i] = minLen;
            mp[sum] = i;
        }
        
        return res == INT_MAX ? -1 : res;
    }
};