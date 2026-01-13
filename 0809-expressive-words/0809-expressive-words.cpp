class Solution {
public:
    bool isExpressive(string &s, string &w) {
        int i = 0, j = 0;
        int n = s.size(), m = w.size();

        while (i < n && j < m) {
            if (s[i] != w[j]) return false;

            int cntS = 0, cntW = 0;
            char c = s[i];

            while (i < n && s[i] == c) {
                cntS++;
                i++;
            }

            while (j < m && w[j] == c) {
                cntW++;
                j++;
            }

            if (cntS < cntW) return false;
            if (cntS > cntW && cntS < 3) return false;
        }

        return i == n && j == m;
    }

    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for (auto &w : words) {
            if (isExpressive(s, w)) count++;
        }
        return count;
    }
};
