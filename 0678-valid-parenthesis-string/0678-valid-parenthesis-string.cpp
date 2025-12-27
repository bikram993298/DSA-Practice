// class Solution {
// public:
//     string s;
//     int n;
//     vector<vector<int>> dp;

//     bool solve(int i, int open) {
//         // invalid
//         if (open < 0) return false;

//         // end of string
//         if (i == n) return open == 0;

//         // memoized
//         if (dp[i][open] != -1)
//             return dp[i][open];

//         bool res = false;

//         if (s[i] == '(') {
//             res = solve(i + 1, open + 1);
//         }
//         else if (s[i] == ')') {
//             res = solve(i + 1, open - 1);
//         }
//         else { // '*'
//             res = solve(i + 1, open + 1) ||   // '('
//                   solve(i + 1, open - 1) ||   // ')'
//                   solve(i + 1, open);         // empty
//         }

//         return dp[i][open] = res;
//     }

//     bool checkValidString(string str) {
//         s = str;
//         n = s.size();
//         dp.assign(n, vector<int>(n + 1, -1));
//         return solve(0, 0);
//     }
// };
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack; // indices of '('
        stack<int> starStack; // indices of '*'

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openStack.push(i);
            } 
            else if (s[i] == '*') {
                starStack.push(i);
            } 
            else { // ')'
                if (!openStack.empty()) {
                    openStack.pop();
                } 
                else if (!starStack.empty()) {
                    starStack.pop();
                } 
                else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*'
        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() > starStack.top())
                return false;
            openStack.pop();
            starStack.pop();
        }

        return openStack.empty();
    }
};

