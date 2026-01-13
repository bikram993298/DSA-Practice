class Solution {
public:
    bool match(string &query, string &pattern) {
        int i = 0, j = 0;

        while (i < query.size()) {
            if (j < pattern.size() && query[i] == pattern[j]) {
                i++;
                j++;
            }
            else if (islower(query[i])) {
                i++;  // skip lowercase
            }
            else {
                return false;  // uppercase mismatch
            }
        }

        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (auto &q : queries) {
            result.push_back(match(q, pattern));
        }
        return result;
    }
};
