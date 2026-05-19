class Solution {
public:
    const int MOD = 1e9 + 7;

    long long dp[100001][2][3][2];
    // behaing as bool
    // main thing to optimze tat just track if you got l one times,,you dont min( then i can be till 10000 iverflow)

    long long solve(int idx, int n, int l, int e, int t) {

        if (idx == n) {

            return (l && e == 2 && t);
        }

        if (dp[idx][l][e][t] != -1)
            return dp[idx][l][e][t];

        long long ans = 0;

        // place 'l',l is needes 1 time so bool
        ans = (ans + solve(idx + 1, n, 1, e, t)) % MOD;

        // place 'e'
        // means if e is needed 2 times so min
        ans = (ans + solve(idx + 1, n, l, min(2, e + 1), t)) % MOD;

        // place 't'
        ans = (ans + solve(idx + 1, n, l, e, 1)) % MOD;

        // place remaining 23 chars
        ans = (ans + 23LL * solve(idx + 1, n, l, e, t)) % MOD;

        return dp[idx][l][e][t] = ans;
    }

    int stringCount(int n) {

        memset(dp, -1, sizeof(dp));

        return solve(0, n, 0, 0, 0);
    }
};