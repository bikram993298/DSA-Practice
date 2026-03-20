// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int>mp;
//         mp[0]=1;
//         int sum=0;
//         vector<int> anss;
//         // for(int i=0;i<nums.size();i++){
//         //     sum=sum+nums[i];
//         //     mp[sum]++;
//         // }
//         // for(int i=0;i<nums.size();i++){
//         //     mp[sum-]
//         // }
//         // sumi freqi
//         // sumi indi
//         // 1 2 3 3 
//         // 1 0
//         // 2 1
//         // 3 {2 3}
//         // map<int,vector<int>>
//         for (int i = 0; i < nums.size(); i++) {
//             mp[nums[i]] = i;
//         }
//         // 2 0
//         // 7 1
//         //,,

//         for (int i = 0; i < nums.size(); i++) {
//             if (mp.find(target - nums[i]) != mp.end()&&mp[target-nums[i]]!=i) {
//                 anss.push_back(i);
//                 anss.push_back(mp[target-nums[i]]);
//                 break;
//             }
//         }
//         return anss;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairIdx;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (pairIdx.find(target - num) != pairIdx.end()) {
                return {i, pairIdx[target - num]};
            }
            pairIdx[num] = i;
        }

        return {};        
    }
};