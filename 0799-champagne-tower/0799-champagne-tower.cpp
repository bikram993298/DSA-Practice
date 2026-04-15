// class Solution {
// public:
//     double dp[101][101];

//     double solve(int p, int q_r, int q_gl) {
//         // invalid position
//         if(q_gl < 0 || q_gl > q_r) return 0;

//         // base case
//         if(q_r == 0 && q_gl == 0) return p;

//         // memo check
//         if(dp[q_r][q_gl] != -1) return dp[q_r][q_gl];

//         // same logic (overflow)
//         double ans = max(0.0, (solve(p, q_r-1, q_gl-1) - 1) / 2.0) +
//                      max(0.0, (solve(p, q_r-1, q_gl) - 1) / 2.0);

//         return dp[q_r][q_gl] = ans;
//     }

//     double champagneTower(int poured, int query_row, int query_glass) {
//         memset(dp, -1, sizeof(dp));
//         return min(1.0, solve(poured, query_row, query_glass));
//     }
// };
class Solution {
public:
    double dp[101][101];
    int P;

    double solve(int r, int c) {
        if(c < 0 || c > r) return 0;

        if(r == 0 && c == 0) return P;

        if(dp[r][c] != -1.0) return dp[r][c];

        double left = solve(r - 1, c - 1);
        double right = solve(r - 1, c);

        double ans = max(0.0, (left - 1) / 2.0) +
                     max(0.0, (right - 1) / 2.0);

        return dp[r][c] = ans;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        // initialize dp with -1// you have explicilty define -1.0 for double
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                dp[i][j] = -1.0;
            }
        }

        P = poured;

        return min(1.0, solve(query_row, query_glass));
    }
};

// Great question — this is **very important in interviews** 🔥
// `memset` vs manual loop behaves **differently for non-int types like double**

// ---

// # ⚠️ Key Difference

// ## ✅ Your loop

// ```cpp
// for(int i = 0; i < 101; i++) {
//     for(int j = 0; j < 101; j++) {
//         dp[i][j] = -1.0;
//     }
// }
// ```

// 👉 Sets each element to:

// ```cpp
// -1.0   // correct double value ✅
// ```

// ---

// ## ❌ memset

// ```cpp
// memset(dp, -1, sizeof(dp));
// ```

// 👉 Sets **byte-by-byte**, not value-wise

// ---

// # 🧠 What actually happens in memset

// `memset(dp, -1, ...)` means:

// 👉 Fill each byte with:

// ```cpp
// 0xFF
// ```

// So for a `double` (8 bytes):

// ```text
// FF FF FF FF FF FF FF FF
// ```

// 👉 This is **NOT guaranteed to be -1.0**

// It becomes:

// ```cpp
// NaN (Not a Number) ❌
// ```

// ---

// # 🔥 Why it matters

// Your check:

// ```cpp
// if(dp[i][j] != -1.0)
// ```

// 👉 If value is NaN:

// ```cpp
// NaN != -1.0 → true
// ```

// 👉 So memoization breaks ❌

// ---

// # ✅ When memset works

// | Type   | memset(-1) safe? |
// | ------ | ---------------- |
// | int    | ✅ (gives -1)     |
// | char   | ✅                |
// | bool   | ⚠️ (not always)  |
// | double | ❌                |
// | float  | ❌                |

// ---

// # 🔥 Interview Rule (VERY IMPORTANT)

// 👉 Use `memset` only for:

// ```cpp
// 0 or -1 for int arrays
// ```

// 👉 For double:

// ```cpp
// use loops or vector initialization
// ```

// ---

// # ⚡ Best Practice

// ```cpp
// fill(&dp[0][0], &dp[0][0] + 101*101, -1.0);
// ```

// 👉 Cleaner than nested loops ✅

// ---

// # 🧠 Interview Answer (PERFECT)

// Say:

// > “memset works at byte level, so it’s unsafe for floating-point arrays. I use loops or fill() for double initialization.”

// ---

// # ⚡ One-line takeaway

// > “memset sets bytes, not values”

// ---

// If you want 🔥
// I can show:

// * memory layout visualization
// * or tricky bugs caused by memset in contests
