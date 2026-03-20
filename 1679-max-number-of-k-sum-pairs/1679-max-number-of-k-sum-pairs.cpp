class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        
        for(int x : nums) {
            int need = k - x;
            
            if(mp[need] > 0) {
                count++;
                mp[need]--;
            } else {
                mp[x]++;
            }
        }
        
        return count;
    }
};