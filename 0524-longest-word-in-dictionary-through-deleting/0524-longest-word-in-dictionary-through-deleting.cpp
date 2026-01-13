class Solution {
public:
    bool isSubsequence(string &s, string &word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) j++;
            i++;
        }
        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for (string &word : dictionary) {
            if (isSubsequence(s, word)) {
                if (word.size() > ans.size() ||
                   (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
