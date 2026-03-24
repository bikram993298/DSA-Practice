class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int i, int buy, int cap, vector<int>& prices) {
        if(i == n || cap == 0) return 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;

        if(buy) {
            profit = max(
                -prices[i] + solve(i+1, 0, cap, prices),  // buy
                solve(i+1, 1, cap, prices)               // skip
            );
        } else {
            profit = max(
                prices[i] + solve(i+1, 1, cap-1, prices), // sell
                solve(i+1, 0, cap, prices)                // skip
            );
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices);
    }
};