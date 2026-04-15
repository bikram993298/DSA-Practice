class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;

        // Step 1: store positions
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        int count = 0;

        // Step 2: check each word
        for(auto &w : words) {
            int prev = -1;
            bool ok = true;

            for(char c : w) {
                if(mp.find(c) == mp.end()) {
                    ok = false;
                    break;
                }

                auto &vec = mp[c];

                // binary search: first index > prev
                auto it = upper_bound(vec.begin(), vec.end(), prev);

                if(it == vec.end()) {
                    ok = false;
                    break;
                }

                prev = *it;
            }

            if(ok) count++;
        }

        return count;
    }
};