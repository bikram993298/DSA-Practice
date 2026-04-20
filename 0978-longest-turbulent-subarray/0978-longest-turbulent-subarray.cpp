class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& arr, int i, int prevSign) {
        if (i == n - 1) return 1;

        if (dp[i][prevSign] != -1)
            return dp[i][prevSign];

        int ans = 1;
        int diff = arr[i] - arr[i + 1];

        // diff > 0 → '>'
        if (diff > 0) {
            if (prevSign == 1) // previous was '<'
                ans = 1 + solve(arr, i + 1, 2);
        }
        // diff < 0 → '<'
        else if (diff < 0) {
            if (prevSign == 2) // previous was '>'
                ans = 1 + solve(arr, i + 1, 1);
        }

        return dp[i][prevSign] = ans;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        n = arr.size();
        dp.assign(n, vector<int>(3, -1));

        int ans = 1;

        for (int i = 0; i < n; i++) {
            // try both starting directions
            ans = max({ans,
                       solve(arr, i, 1),
                       solve(arr, i, 2)});
        }

        return ans;
    }
};