class Solution {
public:

    int n;

    int dp[501][501];

    int solve(int idx, int time,
              vector<int>& satisfaction) {

        if (idx == n)
            return 0;

        if (dp[idx][time] != -1)
            return dp[idx][time];

        // take
        int take =
            satisfaction[idx] * time +
            solve(idx + 1, time + 1, satisfaction);

        // skip
        int skip =
            solve(idx + 1, time, satisfaction);

        return dp[idx][time] = max(take, skip);
    }

    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end());

        n = satisfaction.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, satisfaction);
    }
};