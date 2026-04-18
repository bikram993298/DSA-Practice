// Time: O(N)
// Space: O(N)

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int count = 0;
        // main thing start from last,,remove dahsed then 4 4 ka add

        // traverse from back
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;

            // convert to uppercase
            char ch = toupper(s[i]);
            res += ch;
            count++;

            // add dash after k characters
            if (count == k) {
                res += '-';
                count = 0;
            }
        }

        // remove trailing dash if exists
        if (!res.empty() && res.back() == '-') {
            res.pop_back();
        }

        // reverse final string
        reverse(res.begin(), res.end());

        return res;
    }
};