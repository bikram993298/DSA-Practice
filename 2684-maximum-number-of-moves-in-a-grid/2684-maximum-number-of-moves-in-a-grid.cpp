class Solution {
public:
    int n, m;

    int dp[1001][1001];

    int solve(int i, int j, vector<vector<int>>& grid) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        vector<int> dir = {-1, 0, 1};

        for (int d : dir) {

            int ni = i + d;
            int nj = j + 1;

            if (ni >= 0 && ni < n && nj < m && grid[ni][nj] > grid[i][j]) {

                ans = max(ans, 1 + solve(ni, nj, grid));
            }
        }

        return dp[i][j] = ans;
    }

    int maxMoves(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for (int i = 0; i < n; i++) {

            ans = max(ans, solve(i, 0, grid));
        }

        return ans;
    }
};