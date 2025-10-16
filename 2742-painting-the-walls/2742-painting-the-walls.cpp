class Solution {
public:
    int n;
    vector<int> cost, time;
    vector<vector<int>> dp;
    const int INF = 1e9;

    int solve(int i, int remain) {
        // Base cases
        if (remain <= 0) return 0;          // all walls painted
        if (i == n) return INF;             // no painters left

        if (dp[i][remain] != -1) return dp[i][remain];

        // Option 1: hire this painter
        int hire = cost[i] + solve(i + 1,  remain - time[i] - 1);

        // Option 2: skip this painter
        int skip = solve(i + 1, remain);

        return dp[i][remain] = min(hire, skip);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        this->cost = cost;
        this->time = time;
        n = cost.size();

        dp.assign(n, vector<int>(n + 1, -1));
        return solve(0, n);
    }
};
