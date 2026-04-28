class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == 'R') {
                balance++;
            } else {
                balance--;
            }

            // whenever balance becomes 0,
            // we found one balanced substring
            if (balance == 0) {
                ans++;
            }
        }

        return ans;
    }
};