class Solution {
public:
    const int INF = 1e9;

    int dp[101][21][101];

    int solve(int idx, int prevColor, int groups, vector<int>& houses,
              vector<vector<int>>& cost, int m, int n, int target) {
// all houses processed
        if (idx == m) {

            if (groups == target)
                return 0;

            return INF;
        }
        // too many neighborhoods
        if (groups > target)
            return INF;

        

        // memoization
        if (dp[idx][prevColor][groups] != -1)
            return dp[idx][prevColor][groups];

        int ans = INF;

        // already painted
        if (houses[idx] != 0) {

            int color = houses[idx];

            int newGroups = groups + (color != prevColor);

            ans = solve(idx + 1, color, newGroups, houses, cost, m, n, target);
        }

        // not painted
        else {

            for (int color = 1; color <= n; color++) {

                int newGroups = groups + (color != prevColor);

                ans = min(ans, cost[idx][color - 1] +
                                   solve(idx + 1, color, newGroups, houses,
                                         cost, m, n, target));
            }
        }

        return dp[idx][prevColor][groups] = ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
                int target) {

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, 0, 0, houses, cost, m, n, target);

        return (ans >= INF ? -1 : ans);
    }
};