class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        vector<long long> candidates;
        
        // Edge cases
        // like our no is 1000 then1001 or 999
        //
        candidates.push_back((long long)pow(10, len) + 1);
        candidates.push_back((long long)pow(10, len - 1) - 1);
        
        // Mirror helper
        //1000->1001
        auto makePal = [&](string s) {
            int m = s.size();
            for (int i = 0; i < m / 2; ++i)
                s[m - 1 - i] = s[i];
            return stoll(s);
        };
        
        // Main, +1, -1 versions
        //1101
        //
        string left = n.substr(0, (len + 1) / 2);
        long long leftNum = stoll(left);
        for (long long diff : {-1, 0, 1}) {
            string newLeft = to_string(leftNum + diff);
            string pal = newLeft + n.substr((len + 1) / 2);
            candidates.push_back(makePal(pal));
        }
        
        // Find closest
        long long best = -1;
        for (auto cand : candidates) {
            if (cand == num) continue;
            if (best == -1 ||
                abs(cand - num) < abs(best - num) ||
                (abs(cand - num) == abs(best - num) && cand < best)) {
                best = cand;
            }
        }
        return to_string(best);
    }
};