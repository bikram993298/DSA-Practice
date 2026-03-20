class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        
        for(int x : nums) {
            if(mp.count(x-k)) count += mp[x - k];  // case 1
          if(mp.count(x+k))   count += mp[x + k];  // case 2
            
            mp[x]++;
        }
        
        return count;
    }
};