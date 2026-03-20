class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> mp;
        
        // count frequency
        for(auto &s : nums) {
            mp[s]++;
        }
        
        int count = 0;
        
        for(auto &s : nums) {
            // check if s is prefix
            if(target.substr(0, s.size()) == s) {
                string remain = target.substr(s.size());
                
                count += mp[remain];
                
                // avoid using same index
                if(remain == s) count--;
            }
        }
        
        return count;
    }
};