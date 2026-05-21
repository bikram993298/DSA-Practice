class Solution {
public:
    int dp[505][505];

    int solve(vector<int>& d, int i, int x, int open) {

        // all mismatches processed
        if (i == d.size()) {

            // valid only if no open mismatches left
            return (open == 0 ? 0 : 1e9);
        }

        // memoization
        if (dp[i][open] != -1)
            return dp[i][open];

        int res = 1e9;

        // -----------------------------------
        // OPTION 1:
        // pair adjacent mismatches
        // using adjacent operations
        // -----------------------------------
        if (i < d.size() - 1) {

            res = min(res, d[i + 1] - d[i] + solve(d, i + 2, x, open));
        }

        // -----------------------------------
        // OPTION 2:
        // open current mismatch
        // using global operation
        // -----------------------------------
        res = min(res, x + solve(d, i + 1, x, open + 1));

        // -----------------------------------
        // OPTION 3:
        // close one previously open mismatch
        // -----------------------------------
        if (open > 0) {

            res = min(res, solve(d, i + 1, x, open - 1));
        }

        return dp[i][open] = res;
    }

    int minOperations(string s1, string s2, int x) {

        vector<int> d;

        int n = s1.size();

        // collect mismatch positions
        for (int i = 0; i < n; i++) {

            if (s1[i] != s2[i]) {
                d.push_back(i);
            }
        }

        // impossible if odd mismatches
        if (d.size() % 2)
            return -1;

        memset(dp, -1, sizeof(dp));

        return solve(d, 0, x, 0);
    }
};