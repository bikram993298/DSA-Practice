class Solution {
public:

    int m, n;

    const long long MOD = 1e9 + 7;
    const long long INF = 1e18;

    vector<vector<pair<long long,long long>>> dp;

    pair<long long,long long> solve(int i, int j,
                                    vector<vector<int>>& grid) {

        // out of bounds
        if(i >= m || j >= n) {
            return {-INF, INF};
        }

        // destination
        if(i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        // memoized
        if(dp[i][j].first != INF) {
            return dp[i][j];
        }

        auto right = solve(i, j + 1, grid);
        auto down  = solve(i + 1, j, grid);

        long long val = grid[i][j];

        vector<long long> temp;

        // right path
        if(right.first != -INF) {
            temp.push_back(val * right.first);
            temp.push_back(val * right.second);
        }

        // down path
        if(down.first != -INF) {
            temp.push_back(val * down.first);
            temp.push_back(val * down.second);
        }

        long long mx = *max_element(temp.begin(), temp.end());
        long long mn = *min_element(temp.begin(), temp.end());

        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        dp.assign(m,
                  vector<pair<long long,long long>>
                  (n, {INF, INF}));

        auto ans = solve(0, 0, grid);

        if(ans.first < 0) return -1;

        return ans.first % MOD;
    }
};