// class Solution {
// public:
//     void backtrack(int start, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
//         if (target == 0) {
//             ans.push_back(curr);
//             return;
//         }
//         int n = nums.size();
//         for (int i = start; i < n; ++i) {
//             // skip duplicates on the same recursion level
//             // if (i > start && nums[i] == nums[i-1]) continue;
//             if (nums[i] > target) continue; // pruning, because nums is sorted

//             curr.push_back(nums[i]);
//             backtrack(i + 1, target - nums[i], nums, curr, ans); // i+1 because each number can be used once
//             curr.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         // sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans;
//         vector<int> curr;
//         backtrack(0, target, candidates, curr, ans);
//         return ans;
//     }
// };

// // this code giving this ans duplicate candidates =
// [10,1,2,7,6,1,5]
// target =
// 8
// Output
// [[1,2,5],[1,7],[1,6,1],[2,6],[2,1,5],[7,1]]

// Expected
// [[1,1,6],[1,2,5],[1,7],[2,6]]
// so here remove duplicate you can put sort and during backtrck skip elemts
class Solution {
public:
    void backtrack(int start, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        int n = nums.size();
        for (int i = start; i < n; ++i) {
            // skip duplicates on the same recursion level
            if (i>start && nums[i] == nums[i-1]) continue;
            // start> i means at same reursion lelvel i will not takedouplicate// start=0 means first index of temp,it wil  try eery posiible,then start =1 second level,,is start is 0 lvel means first index is made and you are going to make second char of ans ,,you have to check i> start then duplicate
            if (nums[i] > target) break; // pruning, because nums is sorted

            curr.push_back(nums[i]);
            backtrack(i + 1, target - nums[i], nums, curr, ans); // i+1 because each number can be used once
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // imp after doinh all things badme pata chalega
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, target, candidates, curr, ans);
        return ans;
    }
};

// backtrack(start=0, target=8, curr=[])
// │
// ├── i=0, nums[0]=1 → i>start? (0>0) NO → allowed
// │   curr=[1], backtrack(start=1, target=7)
// │   │
// │   ├── i=1, nums[1]=1 → i>start? (1>1) NO → allowed
// │   │   curr=[1,1], backtrack(start=2, target=6)
// │   │   │
// │   │   ├── i=2, nums[2]=6 → i>start? (2>2) NO → allowed
// │   │   │   curr=[1,1,6], backtrack(start=3, target=0)
// │   │   │   → target==0 ✅ found [1,1,6]
// │   │   │   pop → curr=[1,1]
// │   │   │
// │   │   └── i=3, nums[3]=6 → i>start? (3>2) YES, nums[3]==nums[2]? (6==6) YES → SKIP ❌
// │   │       ← this prevents [1,1,6] duplicate from second 6
// │   │
// │   ├── i=2, nums[2]=6 → i>start? (2>1) YES, nums[2]==nums[1]? (6==1) NO → allowed
// │   │   curr=[1,6], backtrack(start=3, target=1)
// │   │   └── i=3, nums[3]=6 → 6>1 → break
// │   │   pop → curr=[1]
// │   │
// │   └── i=3, nums[3]=6 → i>start? (3>1) YES, nums[3]==nums[2]? (6==6) YES → SKIP ❌
// │
// ├── i=1, nums[1]=1 → i>start? (1>0) YES, nums[1]==nums[0]? (1==1) YES → SKIP ❌
// │   ← this prevents entire duplicate subtree starting with second 1
// │
// ├── i=2, nums[2]=6 → i>start? (2>0) YES, nums[2]==nums[1]? (6==1) NO → allowed
// │   curr=[6], backtrack(start=3, target=2)
// │   └── i=3, nums[3]=6 → 6>2 → break
// │   pop → curr=[]
// │
// └── i=3, nums[3]=6 → i>start? (3>0) YES, nums[3]==nums[2]? (6==6) YES → SKIP ❌