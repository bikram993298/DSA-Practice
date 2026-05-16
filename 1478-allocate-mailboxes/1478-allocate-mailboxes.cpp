class Solution {
public:

    int n;

    int dp[101][101];

    ///

    int solve(int idx, int k,
              vector<vector<int>>& cost) {

        // all houses covered
        if(idx == n && k == 0)
            return 0;

        // invalid case
        if(idx == n || k == 0)
            return 1e9;

        // memoization
        if(dp[idx][k] != -1)
            return dp[idx][k];

        int ans = 1e9;

        // try every possible partition
        for(int j = idx; j < n; j++) {

            ans = min(ans,
                      cost[idx][j] +
                      solve(j + 1, k - 1, cost));
        }

        return dp[idx][k] = ans;
    }

    int minDistance(vector<int>& houses, int k) {

        sort(houses.begin(), houses.end());

        n = houses.size();

        // cost[i][j]
        // minimum cost to cover houses i..j using one mailbox
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                // int len = j - i + 1;

                // double median;

                // // odd number of houses
                // if(len % 2 == 1) {

                //     int mid = (i + j) / 2;

                //     median = houses[mid];
                // }

                // // even number of houses
                // else {

                //     int mid1 = (i + j) / 2;
                //     int mid2 = mid1 + 1;

                //     median =
                //         (houses[mid1] + houses[mid2]) / 2.0;
                // }
                int mid = (i + j) / 2;

for(int x = i; x <= j; x++) {

    cost[i][j] += abs(houses[x] - houses[mid]);
}

              
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, k, cost);
    }
};

// This problem is a very good example of how to build DP thinking gradually instead of jumping directly to the final solution.

// Let's build the thought process naturally.

// ---

// # Step 1 — Ignore `k`

// First think:

// ```txt id="x4m2np"
// If only ONE mailbox existed,
// where should we place it?
// ```

// Example:

// ```txt id="a8v7qd"
// houses = [1,4,8,10]
// ```

// Try positions mentally:

// * near left → right houses far
// * near right → left houses far

// Eventually you observe:

// ```txt id="j5n9wc"
// middle position gives minimum distance
// ```

// That becomes:

// ```txt id="m7r3pb"
// Median minimizes absolute distance
// ```

// VERY important DP habit:

// ```txt id="u1k8vf"
// Solve smaller version first
// ```

// ---

// # Step 2 — One Mailbox for a Range

// Now think:

// ```txt id="v9d2qx"
// What if one mailbox serves only houses i...j ?
// ```

// Example:

// ```txt id="y6f1kt"
// [4,8,10]
// ```

// Best mailbox:

// ```txt id="t3m5lw"
// median = 8
// ```

// Cost:

// ```txt id="k8q4mz"
// |4-8| + |8-8| + |10-8|
// = 6
// ```

// Now huge realization:

// ```txt id="b7v2cx"
// For ANY range i..j,
// I can compute its best single-mailbox cost
// ```

// This creates:

// ```txt id="h2p9ns"
// cost[i][j]
// ```

// This is classic DP preprocessing.

// ---

// # Step 3 — Now Think About k Mailboxes

// Now ask:

// ```txt id="z4t1mw"
// Suppose I am standing at house index i,
// and I still have k mailboxes left.
// What decisions can I make?
// ```

// This is the MOST IMPORTANT DP QUESTION.

// ---

// # Step 4 — First Decision

// You decide:

// ```txt id="s8m3qy"
// How many houses should first mailbox cover?
// ```

// Suppose:

// ```txt id="n6v8pc"
// first mailbox covers i...j
// ```

// Then:

// * cost of this group already known:

// ```txt id="e4q2fd"
// cost[i][j]
// ```

// * remaining problem:

// ```txt id="r1m7xt"
// solve(j+1, k-1)
// ```

// BOOM.

// Smaller subproblem found.

// This is where recursion naturally appears.

// ---

// # Step 5 — Recursive Thinking

// So:

// ```txt id="w5n2kb"
// Try every possible j
// ```

// Take minimum.

// That becomes:

// solve(i,k)=\min(cost[i][j]+solve(j+1,k-1))

// ---

// # Real DP Thinking Pattern

// For hard DP problems, train yourself to ask these small questions:

// ---

// ## 1️⃣ What is the smallest version of problem?

// Here:

// ```txt id="u7c4ld"
// one mailbox
// ```

// ---

// ## 2️⃣ What reusable information exists?

// Here:

// ```txt id="p3q9xn"
// best cost for range i..j
// ```

// ---

// ## 3️⃣ What choice am I making?

// Here:

// ```txt id="z8r5mf"
// where to end current mailbox group
// ```

// ---

// ## 4️⃣ After making choice, what remains?

// Here:

// ```txt id="k2w7ps"
// remaining houses + remaining mailboxes
// ```

// That directly forms DP.

// ---

// # Biggest Mental Shift

// Most students try:

// ```txt id="x9f2qc"
// How do I solve full problem?
// ```

// Instead do:

// ```txt id="q6m1tb"
// What ONE decision am I making right now?
// ```

// DP becomes much easier.

// ---

// # General Template for Partition DP

// This problem belongs to:

// ```txt id="b5v3nd"
// Partition DP
// ```

// Pattern:

// ```txt id="n4x8ql"
// Split array into groups optimally
// ```

// Common problems:

// * Allocate Mailboxes
// * Matrix Chain Multiplication
// * Palindrome Partitioning
// * Burst Balloons
// * Split Array Largest Sum

// ---

// # Universal Partition DP Formula

// Usually:

// dp[i]=\min(\text{current group cost}+dp[next])

// You try all partition endings.

// ---

// # How To Improve DP Thinking

// When practicing:

// Never read final solution immediately.

// Instead ask yourself repeatedly:

// ```txt id="v2q8hs"
// 1. What is my state?
// 2. What decision am I making?
// 3. What smaller problem remains?
// 4. Can I reuse computed answers?
// ```

// That is how strong DP intuition develops.
