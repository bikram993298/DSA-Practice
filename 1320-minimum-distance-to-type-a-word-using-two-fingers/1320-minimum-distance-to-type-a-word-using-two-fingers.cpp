class Solution {
public:
    int dp[301][27][27];

    int distance(int a, int b) {

        // unused finger
        if (a == 26)
            return 0;

        int r1 = a / 6;
        int c1 = a % 6;

        int r2 = b / 6;
        int c2 = b % 6;

        return abs(r1 - r2) + abs(c1 - c2);
        // we have mapped chaacterto distance
        // at first char to 0 to 25 then row coloum devide to make distance
    }

    int solve(int idx, int left, int right, string& word) {

        if (idx == word.size())
            return 0;

        if (dp[idx][left][right] != -1)
            return dp[idx][left][right];

        int cur = word[idx] - 'A';

        // use left finger
        int useLeft = distance(left, cur) + solve(idx + 1, cur, right, word);

        // use right finger
        int useRight = distance(right, cur) + solve(idx + 1, left, cur, word);

        return dp[idx][left][right] = min(useLeft, useRight);
    }

    int minimumDistance(string word) {

        memset(dp, -1, sizeof(dp));
        // o index,26 means not placed in anyy character

        return solve(0, 26, 26, word);
    }
};