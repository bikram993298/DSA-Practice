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
                
                if(mp.count(remain))count += mp[remain];
                
                // avoid using same index like 77  is 5 itmes in the map and we need 77 to fill the string then we only count-1 will add becase samw index,77,77,77,77,77, 4 pair will be there and according rest will be count so,,amin thing if same
                if(remain == s) count--;
            }
        }
        
        return count;
    }
};