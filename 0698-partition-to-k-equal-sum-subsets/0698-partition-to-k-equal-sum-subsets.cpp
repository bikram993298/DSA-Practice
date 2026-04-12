class Solution {
public:
    int target;
    int k_;

    bool solve(vector<int>& nums, vector<bool>& used, int curr, int start, int cnt) {
        
        if (cnt == k_) return true;

        if (curr == target) {
            return solve(nums, used, 0, 0, cnt + 1);
        }

        for (int i = start; i < nums.size(); i++) {
            if (used[i]) continue;
            if (curr + nums[i] > target) continue;

            used[i] = true;

            if (solve(nums, used, curr + nums[i], i + 1, cnt))
                return true;

            used[i] = false;

            // // 🔥 pruning (very important) very ipmortant lets think
            // if (curr == 0) return false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        k_ = k;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;

        vector<bool> used(nums.size(), false);

        return solve(nums, used, 0, 0, 0);
    }
};

//in gfg n==10 so till n=9 n! will run
// class Solution {
//   public:
  
//   int target;
//     int k_;

//     bool solve(vector<int>& nums, vector<bool>& used, int curr, int start, int cnt) {
        
//         if (cnt == k_) return true;

//         if (curr == target) {
//             return solve(nums, used, 0, 0, cnt + 1);
//         }

//         for (int i = start; i < nums.size(); i++) {
//             if (used[i]) continue;
//             if (curr + nums[i] > target) continue;

//             used[i] = true;

//             if (solve(nums, used, curr + nums[i], i + 1, cnt))
//                 return true;

//             used[i] = false;

//             // // 🔥 pruning (very important) very ipmortant lets think
//             // if (curr == 0) return false;
//         }

//         return false;
//     }

//     bool isKPartitionPossible(vector<int> &nums, int k) {
//         // Your code here
//          k_ = k;
//         int sum = accumulate(nums.begin(), nums.end(), 0);

//         if (sum % k != 0) return false;

//         target = sum / k;

//         // sort(nums.rbegin(), nums.rend());

//         // if (nums[0] > target) return false;

//         vector<bool> used(nums.size(), false);

//         return solve(nums, used, 0, 0, 0);
//     }
// };


// Great question — this is a **core concept** for DSA + interviews 🔥

// ---

// # 🧠 Permutation vs Combination (Simple Understanding)

// ## 🔴 Permutation = Order Matters

// 👉 If **order changes → it's a different answer**

// Example:

// ```text
// [1,2] ≠ [2,1]
// ```

// Both are counted separately.

// ### Example:

// Choose 2 from {1,2,3}

// Permutations:

// ```text
// (1,2), (2,1), (1,3), (3,1), (2,3), (3,2)
// ```

// 👉 Total = **6**

// ---

// ## 🟢 Combination = Order DOESN’T Matter

// 👉 If same elements → same answer

// Example:

// ```text
// [1,2] = [2,1]
// ```

// Only counted once.

// ### Example:

// Choose 2 from {1,2,3}

// Combinations:

// ```text
// (1,2), (1,3), (2,3)
// ```

// 👉 Total = **3**

// ---

// # 🔥 Formula Difference

// ## Permutation:

// ```text
// nPr = n! / (n - r)!
// ```

// ## Combination:

// ```text
// nCr = n! / (r! * (n - r)!)
// ```

// ---

// # ⚡ Key Difference (IMPORTANT)

// | Feature        | Permutation             | Combination     |
// | -------------- | ----------------------- | --------------- |
// | Order matters? | ✅ Yes                   | ❌ No            |
// | Count          | Larger                  | Smaller         |
// | Example        | passwords, arrangements | subsets, groups |

// ---

// # 🧠 In DSA (VERY IMPORTANT)

// ### 🔴 Permutation pattern

// ```cpp
// for (int i = 0; i < n; i++)
// ```

// 👉 tries all orders

// ---

// ### 🟢 Combination pattern

// ```cpp
// for (int i = start; i < n; i++)
// ```

// 👉 avoids duplicates

// ---

// # 🔥 Your Problem Connection

// In your code:

// ### ❌ Without `start`

// ```text
// You generate permutations → O(n!)
// ```

// ### ✅ With `start`

// ```text
// You generate combinations → O(2^n)
// ```

// ---

// # 🚀 Real-Life Intuition

// ### Permutation:

// 👉 “Who sits where?”

// ```text
// A-B ≠ B-A
// ```

// ---

// ### Combination:

// 👉 “Who is in the group?”

// ```text
// A-B = B-A
// ```

// ---

// # 🧠 Interview One-Liner

// If asked:

// > “Difference between permutation and combination?”

// Say:

// > “Permutation considers order, combination doesn’t. In coding, permutation explores all arrangements, while combination avoids duplicates using a start index.”

// ---

// ## 👉 If You Want

// I can show:

// * 🔥 How to identify permutation vs combination instantly in any problem
// * ⚡ Common LeetCode problems for both patterns
// * 🧠 Trick to convert one into another

// Just say 👍
