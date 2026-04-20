class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        
        int l = 0;
        int count = 0;

        for (int r = 0; r < n; r++) {
            
          
            
            mp[nums[r]]++;

            // shrink if distinct > k
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }

            // add all subarrays ending at r
            count += (r - l + 1);

          
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};