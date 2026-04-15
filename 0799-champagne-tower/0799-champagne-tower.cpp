class Solution {
public:
    double dp[101][101];
    int P;

    double solve(int r, int c) {
        if(c < 0 || c > r) return 0;

        if(r == 0 && c == 0) return P;

        if(dp[r][c] != -1.0) return dp[r][c];

        double left = solve(r - 1, c - 1);
        double right = solve(r - 1, c);

        double ans = max(0.0, (left - 1) / 2.0) +
                     max(0.0, (right - 1) / 2.0);

        return dp[r][c] = ans;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        // initialize dp with -1
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                dp[i][j] = -1.0;
            }
        }

        P = poured;

        return min(1.0, solve(query_row, query_glass));
    }
};