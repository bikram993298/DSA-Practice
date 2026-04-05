class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;

        int sum = 1;

        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                sum += i;
                //one time two deisor e are adding like 24 ,,2*12 two deesor add now for perfect square 4 *4 16 ,one time add

                if(i != num / i) {
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};


// Great question — this line is **very important** 👇

// ```cpp
// if(i != num / i) {
//     sum += num / i;
// }
// ```

// ---

// ## 💡 Why do we need this?

// When we find a divisor `i`, we also get another divisor:

// ```
// i × (num / i) = num
// ```

// 👉 So divisors always come in **pairs**

// ---

// ## 🧠 Example: num = 28

// When `i = 2`:

// * `2` is a divisor
// * `28 / 2 = 14` is also a divisor

// So we add both:

// ```
// sum += 2 + 14
// ```

// ---

// ## ⚠️ Special Case: Perfect Square

// Consider `num = 36`

// When `i = 6`:

// * `6 × 6 = 36`
// * Both divisors are **same**

// 👉 If we do:

// ```
// sum += 6 + 6 ❌ (wrong, double counting)
// ```

// ---

// ## ✅ That’s why we check:

// ```cpp
// if(i != num / i)
// ```

// * If they are **different** → add both
// * If they are **same** → add only once

// ---

// ## 🔥 Summary

// | Case         | Action            |
// | ------------ | ----------------- |
// | `i != num/i` | Add both divisors |
// | `i == num/i` | Add only once     |

// ---

// ## 🚀 One-line Insight

// 👉 *“Avoid double counting when divisor pair collapses into one (perfect square case)”*

// ---

// If you want, I can show:

// * 🔥 Visualization of divisor pairing (very intuitive)
// * 🔥 How this pattern appears in many DSA problems (factorization, GCD, etc.)
