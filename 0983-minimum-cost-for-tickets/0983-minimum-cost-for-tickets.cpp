class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& days, vector<int>& costs, int i) {
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

       

        // 1-day pass
        int cost1 = costs[0] + solve(days, costs, i + 1);

        // 7-day pass
        int j = i;
        while (j < n && days[j] < days[i] + 7) j++;
        int cost7 = costs[1] + solve(days, costs, j);

        // 30-day pass
        j = i;
        while (j < n && days[j] < days[i] + 30) j++;
        int cost30 = costs[2] + solve(days, costs, j);

        ans = min({cost1, cost7, cost30});



        return dp[i] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.assign(n, -1);

        return solve(days, costs, 0);
    }
};