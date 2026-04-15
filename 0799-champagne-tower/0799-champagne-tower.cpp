class Solution {
public:
    double dp[101][101];

    double solve(int p, int q_r, int q_gl) {
        // invalid position
        if(q_gl < 0 || q_gl > q_r) return 0;

        // base case
        if(q_r == 0 && q_gl == 0) return p;

        // memo check
        if(dp[q_r][q_gl] != -1) return dp[q_r][q_gl];

        // same logic (overflow)
        double ans = max(0.0, (solve(p, q_r-1, q_gl-1) - 1) / 2.0) +
                     max(0.0, (solve(p, q_r-1, q_gl) - 1) / 2.0);

        return dp[q_r][q_gl] = ans;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        memset(dp, -1, sizeof(dp));
        return min(1.0, solve(poured, query_row, query_glass));
    }
};