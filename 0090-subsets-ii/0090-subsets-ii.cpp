// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
//       int n = nums.size();
//     set<vector<int>> uniqueSubsets;
    

//     for (int val = 0; val < (1 << n); val++) {
//         vector<int> subset;
//         for (int bit = 0; bit < n; bit++) {
//             if (val & (1 << bit)) {
//                 subset.push_back(nums[bit]);
//             }
//         }
//         sort(subset.begin(), subset.end());
//         uniqueSubsets.insert(subset);
//     }
    
    
//     vector<vector<int>> subsets(uniqueSubsets.begin(), uniqueSubsets.end());
//     return subsets;
//     }
// };
class Solution {
public:
    vector<vector<int>> res;

    void solve(int idx, vector<int>& nums, vector<int>& temp) {
        res.push_back(temp);

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(i + 1, nums, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(0, nums, temp);
        return res;
    }
};