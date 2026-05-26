class Solution {
public:
    int countGoodSubstrings(string s) {

        int n = s.size();

        // less than 3 characters means impossible
        if(n < 3) return 0;

        int count = 0;

        // check every substring of size 3
        for(int i = 0; i <= n - 3; i++) {

            char a = s[i];
            char b = s[i + 1];
            char c = s[i + 2];

            // all three must be distinct
            if(a != b && b != c && a != c) {
                count++;
            }
        }

        return count;
    }
};