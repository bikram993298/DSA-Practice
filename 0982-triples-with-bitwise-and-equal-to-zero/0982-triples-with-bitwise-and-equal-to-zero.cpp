class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        
        // Step 1: pair AND
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums[i] & nums[j]]++;
            }
        }
        
        int ans = 0;
        
        // Step 2: check with third element
        for(int k=0;k<n;k++){
            for(auto &it : mp){
                if((it.first & nums[k]) == 0){
                    ans += it.second;
                }
            }
        }
        
        return ans;
    }
};