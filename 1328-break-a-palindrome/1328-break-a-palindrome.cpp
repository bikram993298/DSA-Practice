class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.size();

        // single char
        if (n == 1)
            return "";

        // check first half
        for (int i = 0; i < n / 2; i++) {

            if (palindrome[i] != 'a') {

                palindrome[i] = 'a';

                return palindrome;
            }
        }

        // all 'a'
        palindrome[n - 1] = 'b';

        return palindrome;
    }
};