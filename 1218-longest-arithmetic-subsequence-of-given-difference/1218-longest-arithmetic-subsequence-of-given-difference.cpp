// //Approach-2 (Recursion + Memo with 1-D Memo) - Time Limit Exceeded
// class Solution {
// public:
//     int n;
//     int D;
//     int t[100001];
//     int solve(int idx, vector<int>& arr) {
        
//         if(t[idx] != -1)
//             return t[idx];
        
//         int result = 0;
        
//         for(int i = idx+1; i < n; i++) {
//             int prevVal = arr[idx];
//             int currVal = arr[i];


//             if (currVal - prevVal == D)
//                 result = max(result, 1 + solve(i, arr));
//         }
        
//         return t[idx] = result;
//     }
    
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int result = 0;
//         n = arr.size();
//         D = difference;
        
//         memset(t, -1, sizeof(t));
        
//         for (int i = 0; i < n; i++) {
//             result = max(result, 1 + solve(i, arr));
//         }

//         return result;
//     }
// };
// Absolutely 👍
// Here are **clean, exam-/interview-ready notes** on **when to use `vector` vs `map / unordered_map` in DP**.

// You can literally **memorize this page**.

// ---

// # 📌 DP Storage Choice: `vector` vs `map`

// ---

// ## 1️⃣ Use **`vector`** when

// ### ✅ DP index is **small & bounded**

// * Index range known in advance
// * Size ≤ ~1e6 (safe in C++)

// Examples:

// ```text
// i ∈ [0..n]
// sum ∈ [0..1000]
// diff ∈ [-500..500]  (after shifting)
// ```

// ---

// ### ✅ DP index is **dense**

// * Most indices will be used
// * No large gaps

// ---

// ### ✅ Access speed is critical

// * `vector` access = **O(1)** (fastest)
// * Cache-friendly

// ---

// ### ✅ Typical problems

// | Problem                               | DP          |
// | ------------------------------------- | ----------- |
// | LIS (n² DP)                           | dp[i]       |
// | Knapsack                              | dp[weight]  |
// | Coin change                           | dp[sum]     |
// | Arithmetic subsequence (bounded diff) | dp[i][diff] |
// | String DP                             | dp[i][j]    |

// ---

// ### ✅ Example

// ```cpp
// vector<int> dp(n+1);
// dp[i] = dp[i-1] + 1;
// ```

// ---

// ## 2️⃣ Use **`map / unordered_map`** when

// ### ❌ DP index is **large**

// * Index can be up to `1e9` or negative

// ---

// ### ❌ DP index is **sparse**

// * Only a few values actually appear

// ---

// ### ❌ Index is a **value**, not position

// * DP keyed by number itself

// ---

// ### ✅ Typical problems

// | Problem                               | DP                   |
// | ------------------------------------- | -------------------- |
// | Longest arithmetic subsequence (1218) | dp[value]            |
// | Make array strictly increasing        | dp[index][prevValue] |
// | Difference-based DP                   | dp[value - diff]     |
// | State compression DP                  | dp[stateMask]        |
// | Graph DP                              | dp[node]             |

// ---

// ### ✅ Example

// ```cpp
// unordered_map<int,int> dp;
// dp[x] = dp[x - d] + 1;
// ```

// ---

// ## 3️⃣ `unordered_map` vs `map`

// | Feature   | unordered_map | map        |
// | --------- | ------------- | ---------- |
// | Lookup    | O(1) avg      | O(log n)   |
// | Order     | ❌ unordered   | ✅ ordered  |
// | Speed     | faster        | slower     |
// | Interview | preferred     | acceptable |

// 👉 Default choice: **`unordered_map`**

// ---

// ## 4️⃣ Hybrid case: **Vector + Map**

// Sometimes DP is:

// ```text
// dp[i][value]
// ```

// Where:

// * `i` is small → `vector`
// * `value` is large → `map`

// ### Example

// ```cpp
// vector<unordered_map<int,int>> dp(n);
// ```

// Used in:

// * Longest arithmetic subsequence (1027)
// * Difference DP

// ---

// ## 5️⃣ Coordinate Compression (Advanced)

// When:

// * Values are large
// * But number of distinct values is small

// Then:

// 1. Compress values → `[0..k)`
// 2. Use vector instead of map

// Example:

// ```cpp
// value → compressedIndex
// ```

// ---

// ## 6️⃣ Common Mistakes (AVOID ❌)

// ❌ Using vector when index is value up to `1e9`
// ❌ Using map when index is simple `[0..n]`
// ❌ Forgetting negative indices
// ❌ Using map when dense DP is possible

// ---

// ## 7️⃣ Interview-ready explanation (MEMORIZE)

// > “I use vector when the DP index is small and dense. When the DP is indexed by values that can be large or sparse, I use an unordered_map to store only reachable states.”

// ---

// ## 🔑 One-line takeaway

// > **Vector → small & dense indices
// > Map → large or sparse indices**

// ---

// If you want:

// * real problems mapped to these rules
// * memory limits discussion
// * when compression beats map

// Just tell me 👍


//Approach-3 (DP using Map) - O(n) - Accepted
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int n = arr.size();
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            
            int prev            = arr[i] - difference;
            
            int lengt_till_prev = mp[prev];
            
            mp[arr[i]] = lengt_till_prev + 1;
            
            result = max(result, mp[arr[i]]);
        }
        
        return result;
    }
};