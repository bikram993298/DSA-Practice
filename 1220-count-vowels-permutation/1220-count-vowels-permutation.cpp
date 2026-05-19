class Solution {
public:
    const int MOD = 1e9 + 7;

    long long dp[20001][5];

    vector<vector<int>> nextVowel = {
        {1},          // a -> e
        {0, 2},       // e -> a, i
        {0, 1, 3, 4}, // i -> a, e, o, u
        {2, 4},       // o -> i, u
        {0}           // u -> a
    };

    long long solve(int idx, int n, int vowel) {

        // reached length n
        if (idx == n)
            return 1;

        if (dp[idx][vowel] != -1)
            return dp[idx][vowel];

        long long ways = 0;

        for (int next : nextVowel[vowel]) {

            ways = (ways + solve(idx + 1, n, next)) % MOD;
        }

        return dp[idx][vowel] = ways;
    }

    int countVowelPermutation(int n) {

        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        // start from each vowel
        for (int v = 0; v < 5; v++) {

            ans = (ans + solve(1, n, v)) % MOD;
        }

        return ans;
    }
};