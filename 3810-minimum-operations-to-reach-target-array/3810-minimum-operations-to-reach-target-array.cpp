class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])&& nums[i]!=target[i]) mp[nums[i]]++;
        }
        

        return mp.size();
    }
};