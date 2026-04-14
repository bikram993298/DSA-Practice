class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1; // last two selected
        int ans = 0;

        for (auto &it : intervals) {
            int l = it[0], r = it[1];

            // Case 1: already covered
            if (l <= a) continue;
            // a nd b gives the two selected numbers,,if no overlap thne chosse right most a and b,,then if one is is overla p then select a as b ,,becuse first overlap that then b will be last ending or r,,if whole overlap then ocnitnue; sort by end because furture call and ending se you have to maximize so that ,,if ending equal then starting ssssse descending matlab jo jada bara o age

            // Case 2: only one point inside
            if (l <= b) {
                ans += 1;
                a = b;
                b = r;
            }
            // Case 3: need two points
            else {
                ans += 2;
                // end point and before 1 end point
                a = r - 1;
                b = r;
            }
        }

        return ans;
    }
};

// Great — this is exactly the **deep intuition** interviewers are looking for.
// Let’s make it **crystal clear so you can derive it in the interview** 🔥

// ---

// # 🧠 Step 1: What is the real goal?

// We need:

// 👉 Each interval must contain **at least 2 selected points**
// 👉 Minimize total points

// ---

// # 🧠 Step 2: Ask yourself THIS question (key to derive greedy)

// > “If I must choose points for an interval, where should I place them so they help future intervals too?”

// ---

// # 🎯 Critical Insight

// 👉 Future intervals will likely be **to the right**

// So:

// 👉 If I place points **towards the right end**, they can be reused

// ---

// # 🔥 Now comes the decision

// ## ❓ Which interval should I process first?

// Two options:

// ### Option A: Sort by start ❌

// * You process big intervals early
// * You don’t know future constraints yet
// * You may waste points

// ---

// ### Option B: Sort by end ✅

// 👉 You process the interval that **ends earliest**

// Why is this powerful?

// ---

// # 💡 KEY GREEDY PRINCIPLE

// > "Always satisfy the most restrictive interval first"

// ---

// # 🔍 Why smallest end is most restrictive?

// Example:

// ```
// [2,3]  ← very tight
// [1,10] ← very flexible
// ```

// 👉 If you don’t satisfy `[2,3]` properly NOW
// you **lose the chance forever**

// But `[1,10]` can be satisfied later

// ---

// # 🔥 So strategy becomes:

// 1. Handle smallest end interval first
// 2. Place points at **rightmost positions**
// 3. Those points will help future intervals

// ---

// # 🧪 Visual Intuition

// Consider:

// ```
// [2,3] → must pick inside {2,3}
// ```

// Best choice:

// ```
// pick 2, 3
// ```

// Now for future:

// ```
// [1,10]
// ```

// 👉 Already satisfied ✅

// ---

// # ❌ If you did reverse

// Pick for `[1,10]` first:

// ```
// pick 9,10
// ```

// Then:

// ```
// [2,3] → not covered ❌
// ```

// ---

// # 🧠 How to Derive in Interview (SCRIPT)

// Say this:

// > "I want to place points so they help as many future intervals as possible.
// > That suggests placing them towards the right.
// > To make greedy safe, I should first handle the interval with the smallest end — because it has the least flexibility.
// > This ensures I don’t miss satisfying tight intervals."

// ---

// # 🔥 One-Line Memory Trick

// 👉 **“Smallest end = least freedom = handle first”**

// ---

// # ⚡ Why start sorting fails (1-line logic)

// 👉 Start sorting processes **flexible intervals first**, which is unsafe

// ---

// # 🧠 Pattern Recognition

// Whenever you see:

// * intervals
// * minimize points
// * reuse across intervals

// 👉 Think:

// **Sort by end + greedy from right**

// ---

// # 🚀 Final Confidence Boost

// In interview, you DON’T need proof — just say:

// > "This follows the standard greedy pattern of interval scheduling — processing by earliest end ensures optimal decisions."

// ---

// If you want next level mastery 🚀
// I can show:
// 👉 formal **exchange argument proof (very impressive)**
// 👉 or **how to derive this pattern in ANY greedy problem**
