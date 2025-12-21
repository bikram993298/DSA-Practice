class Solution {
public:
    int n, m;
    const int INF = 1e9;
    const int FULL = (1 << 17) - 1;

    vector<vector<unordered_map<int,int>>> dp;

    int solve(int i, int j, int curAnd,
              vector<int>& nums, vector<int>& andValues) {

        if (j == m) return (i == n ? 0 : INF);
        if (i == n) return INF;

        if (dp[i][j].count(curAnd))
            return dp[i][j][curAnd];

        int ans = INF;
        int newAnd = curAnd & nums[i];

        // stop segment
        if (newAnd == andValues[j]) {
            ans = min(ans,
                      nums[i] + solve(i+1, j+1, FULL,
                                      nums, andValues));
        }

        // continue segment
        if (newAnd >= andValues[j]) {
            ans = min(ans,
                      solve(i+1, j, newAnd,
                            nums, andValues));
        }

        return dp[i][j][curAnd] = ans;
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size();
        m = andValues.size();

        dp.assign(n, vector<unordered_map<int,int>>(m));

        int res = solve(0, 0, FULL, nums, andValues);
        return res == INF ? -1 : res;
    }
};
