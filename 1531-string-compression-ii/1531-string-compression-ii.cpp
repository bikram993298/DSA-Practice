static int dp[101][27][101][101];
class Solution {
public:

    //  static int dp[101][27][101][101];

    int solve(int idx, int prev, int cnt,
              int k, string& s) {

        if (k < 0)
            return 1e9;

        if (idx == s.size())
            return 0;

        if (dp[idx][prev][cnt][k] != -1)
            return dp[idx][prev][cnt][k];

        int res = 1e9;

        // delete current char
        res = solve(idx + 1, prev, cnt, k - 1, s);

        int curr = s[idx] - 'a';

        // keep current char
        if (curr == prev) {

            int add = 0;

            // compressed length increases here
            if (cnt == 1 || cnt == 9 || cnt == 99)
                add = 1;

            res = min(res,
                      add + solve(idx + 1,
                                  prev,
                                  cnt + 1,
                                  k,
                                  s));
        }
        else {

            // start new group
            res = min(res,
                      1 + solve(idx + 1,
                                curr,
                                1,
                                k,
                                s));
        }

        return dp[idx][prev][cnt][k] = res;
    }

    int getLengthOfOptimalCompression(string s, int k) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 26, 0, k, s);
    }
};