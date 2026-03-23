// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//        int n = nums.size();
//        vector<vector<int>> subsets;
//        for (int val = 0; val < (1 << n); val++) {
//             // 0000 -> 0001 -> 0010 ... 1111
//             vector<int> subset;
//             for (int bit = 0; bit <= n-1; bit++) {
//                 if (val & (1 << bit)){
//                     subset.push_back(nums[bit]);
//                 }
//             }
          
//             subsets.push_back(subset);
//        }
//        return subsets;
//     }
// };
class Solution {
public:
    vector<vector<int>> result;

    void solve(int index, vector<int>& nums, vector<int>& temp) {
        result.push_back(temp);

        for(int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(i + 1, nums, temp);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return result;
    }
};