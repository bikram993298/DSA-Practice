class Solution {
public:
    bool isSubsequence(string &a, string &b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }

    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        
        sort(strs.begin(), strs.end(), [](string &a, string &b) {
            return a.size() > b.size();
        });

        for (int i = 0; i < n; i++) {
            bool uncommon = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            if (uncommon) return strs[i].size();
        }

        return -1;
    }
};//why osrting becuaselongest find