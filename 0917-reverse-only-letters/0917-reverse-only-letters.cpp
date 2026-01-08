class Solution {
public:
    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z');
    }

    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (!isAlpha(s[l])) {
                l++;
            } else if (!isAlpha(s[r])) {
                r--;
            } else {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};
