class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;

        for(int x : nums) mp[x]++;

        int i = 0;
        for(auto it : mp){
            nums[i++] = it.first;
        }

        return mp.size();
    }
};