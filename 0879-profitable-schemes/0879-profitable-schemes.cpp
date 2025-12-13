class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[101][101][101];
    int n, minProfit, m;
    vector<int> group, profit;

    int solve(int i, int people, int prof) {
       
        if (people > n) return 0;

       
        if (i == m) {
            return (prof == minProfit) ? 1 : 0;
        }

        // cap profit
        prof = min(prof, minProfit);

        if (dp[i][people][prof] != -1)
            return dp[i][people][prof];

        // skip crime
        int notTake = solve(i + 1, people, prof);

        // take crime
        int take = solve(
            i + 1,
            people + group[i],
            prof + profit[i]
        );

        return dp[i][people][prof] = (take + notTake) % MOD;
    }

    int profitableSchemes(int N, int minP, vector<int>& grp, vector<int>& prof) {
        n = N;
        minProfit = minP;
        group = grp;
        profit = prof;
        m = group.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
