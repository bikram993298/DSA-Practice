class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        // so we are storing in terms of coniguis two ,,and finding in map is there exist somethin like two sum
        for(int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i+1];
            
            if(st.count(sum)) {
                return true;
            }
            
            st.insert(sum);
        }
        
        return false;
    }
};