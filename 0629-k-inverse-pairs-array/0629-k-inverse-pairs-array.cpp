// class Solution {
// public:

//     int MOD = 1e9 + 7;

//     int N, K;

//     vector<vector<int>> dp;

//     int solve(int num, int inv) {

//         // too many inverse pairs
//         if(inv > K)
//             return 0;

//         // used all numbers
//         if(num > N)
//             return (inv == K);

//         // already computed
//         if(dp[num][inv] != -1)
//             return dp[num][inv];

//         long long ans = 0;

//         // insert current number
//         // creates x new inverse pairs
//         for(int x = 0; x <= num - 1; x++) {

//             // pruning
//             if(inv + x > K)
//                 break;

//             ans += solve(num + 1,
//                          inv + x);

//             ans %= MOD;
//         }

//         return dp[num][inv] = ans;
//     }

//     int kInversePairs(int n, int k) {

//         N = n;
//         K = k;

//         dp.assign(n + 2,
//                   vector<int>(k + 1, -1));

//         return solve(1, 0);
//     }
// };
class Solution {
public:

    int kInversePairs(int n, int k) {

        int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, 0));

        dp[0][0] = 1;
        // oth number se 0 inverse aray empty array
        // i indicates how many number you are using,,j indicates in one array howmany invers pair exit
        // thinkinh lets hink in this way we have 3 numbere 1 2 3 and make inverse 2 pair how mnay arrayss,,so what will u don,,try all posiibility push 1, push 2,push 3 then agian next their perpective call.
        // when u push then that menasno inverse pait it is denoting to right beacuse it is dmallets so,,j,,when u push 2,,that means 2 can conrtibute 1,,because in left whenever you push 1,3 it will feintely give 1 contibution so new state i-1,j-1,,thus it will work now think first index i sdone lets think you pushed 2, now thenn next will be (1,3) we can map it to 1,2 and stare(i-1,j-1) now wee need j-1 inversion pair,thus it work,,


        for(int i = 1; i <= n; i++) {

            long long prefix = 0;

            for(int j = 0; j <= k; j++) {

                // add current contribution
                prefix += dp[i - 1][j];

                // remove out-of-window value
                if(j >= i) {
                    prefix -= dp[i - 1][j - i];
                }

                prefix = (prefix % MOD + MOD) % MOD;

                dp[i][j] = prefix;
            }
        }

        return dp[n][k];
    }
};

// First Recall Original Formula

// Without optimization:

// dp[i][j]
// =
// dp[i-1][j]
// +
// dp[i-1][j-1]
// +
// dp[i-1][j-2]
// ...
// +
// dp[i-1][j-(i-1)]

// because current number i can create:

// 0 → i-1

// new inverse pairs.

// Problem

// Computing this sum every time is expensive.

// Example:

// for every dp[i][j]
// loop i times

// Total:

// O(n²*k)
// Main Optimization Idea

// These sums overlap heavily.

// Example

// Suppose:

// i = 4

// Then:

// dp[4][5]

// Needs:

// dp[3][5]
// + dp[3][4]
// + dp[3][3]
// + dp[3][2]
// dp[4][6]

// Needs:

// dp[3][6]
// + dp[3][5]
// + dp[3][4]
// + dp[3][3]

// Notice overlap?

// Almost same window.