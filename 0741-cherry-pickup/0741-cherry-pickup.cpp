class Solution {
public:
    int n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;

        // boundary & thorn check
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        // reached destination
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        int &res = dp[r1][c1][r2];
        if (res != -1) return res;

        int cherries;
        if (r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];

        int best = max({
            solve(r1 + 1, c1, r2 + 1), // down, down
            solve(r1, c1 + 1, r2),     // right, right
            solve(r1 + 1, c1, r2),     // down, right
            solve(r1, c1 + 1, r2 + 1)  // right, down
        });

        return res = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(0, 0, 0));
    }
};
