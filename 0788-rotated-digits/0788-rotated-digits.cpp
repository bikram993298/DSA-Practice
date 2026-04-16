// class Solution {
// public:
//     bool isGood(int num) {
//         bool changed = false;
// // A number is good if:

// // all digits are valid
// // at least one digit changes after rotation
//         while(num > 0) {
//             int d = num % 10;

//             // invalid digits
//             if(d == 3 || d == 4 || d == 7) return false;

//             // digits that change
//             if(d == 2 || d == 5 || d == 6 || d == 9) {
//                 changed = true;
//             }

//             num /= 10;
//         }

//         return changed;
//     }

//     int rotatedDigits(int n) {
//         int count = 0;

//         for(int i = 1; i <= n; i++) {
//             if(isGood(i)) count++;
//         }

//         return count;
//     }
// };


class Solution {
public:
    string s;
    int dp[11][2][2];

    int solve(int pos, bool tight, bool changed) {
        if(pos == s.size()) {
            return changed ? 1 : 0;
        }

        if(dp[pos][tight][changed] != -1)
            return dp[pos][tight][changed];

        int limit = tight ? s[pos] - '0' : 9;
        int ans = 0;

        for(int d = 0; d <= limit; d++) {
            // skip invalid digits
            if(d == 3 || d == 4 || d == 7) continue;

            bool newChanged = changed || (d == 2 || d == 5 || d == 6 || d == 9);

            ans += solve(pos + 1,
                         tight && (d == limit),
                         newChanged);
        }

        return dp[pos][tight][changed] = ans;
    }

    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));

        return solve(0, 1, 0);
    }
};