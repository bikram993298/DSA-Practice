class Solution {
public:
    bool hasAllCodes(string s, int k) {

// main idea is k leght ka all subtring pu in set find size or uniq substring then ,,2^ k subtring if equal then yes
        unordered_set<string> st;
                if (s.size() < k) return false;


        for (int i = 0; i <= s.size() - k; i++) {

            st.insert(s.substr(i, k));
        }

        return st.size() == (1 << k);
    }
};