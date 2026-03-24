class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void backtrack(int i, string& s, vector<string>& path) {
        if (i == s.size()) {
            result.push_back(path);
            return;
        }
        // start = 0, end = 2
        // path = []
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, s, path);
                path.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(0, s, path);
        return result;
    }
};
