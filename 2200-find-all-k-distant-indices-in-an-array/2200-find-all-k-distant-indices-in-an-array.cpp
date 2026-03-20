// class Solution {
// public:
//     vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
//         int n = nums.size();
//         vector<int> res;
        
//         vector<int> keyIndex;
        
//         // Step 1: store key positions
//         for(int i = 0; i < n; i++) {
//             if(nums[i] == key) {
//                 keyIndex.push_back(i);
//             }
//         }
        
//         // Step 2: check each index
//         for(int i = 0; i < n; i++) {
//             for(int j : keyIndex) {
//                 if(abs(i - j) <= k) {
//                     res.push_back(i);
//                     break;
//                 }
//             }
//         }
        
//         return res;
//     }
// };


// // ⏱ O(n × number_of_keys)
// // it also 0(n*n) time complexcity


// # 🚀 Method 3: Most Optimal (Two Pointer)

// ## 💡 Idea

// 👉 Maintain pointer on key indices
// 👉 Expand valid range

// ---

// ## ✅ Code (Best)

// ```cpp
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size();
        
        int last = -1;  // last key index
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                
                // avoid duplicates
                start = max(start, last + 1);

                // like here cann be sittuaion of overlap start to end you added ,,then in the next agian you area dding start to end,,this may be different so use last index 
                
                for(int j = start; j <= end; j++) {
                    res.push_back(j);
                }
                
                last = end;
            }
        }
        
        return res;
    }
};
// ```

// ---

// # ⏱ Complexity

// * Time: **O(n)**
// * Space: **O(1)** (excluding result)

// ---

// # 🔥 Key Insight

// 👉 Instead of checking every pair:

// ```text
// Convert condition into intervals
// ```

// Then merge intervals while iterating.

// ---

// # 🎯 Interview Answer

// > I find all indices where nums[j] == key, then for each such index I add the range [j−k, j+k]. To avoid duplicates, I merge overlapping ranges. This gives an O(n) solution.

// ---

// # 🧠 Pattern Recognition

// This is:

// 👉 **Range expansion + merging intervals**

// Similar to:

// * Merge intervals
// * Sliding window coverage problems

// ---

// # 🚀 Your Turn

// If interviewer asks:

// 👉 “Return count instead of indices”

// How would you optimize further?

// (Hint: avoid storing result)
