class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                // one deletion allowed
                //either you can skip ith index or rth index,,
                //like example abca,,
                //a==a continue
                //b!=c
                //two option either skip or skip c
                return isPalindrome(s, l + 1, r) ||
                       isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};
