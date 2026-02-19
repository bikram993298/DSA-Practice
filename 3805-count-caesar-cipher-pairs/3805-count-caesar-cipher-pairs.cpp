class Solution {
public:

    string normalize(string s) {

        int shift = s[0] - 'a';

        string res;

        for(char c : s) {

            res.push_back((c - shift + 26) % 26 + 'a');
        }

        return res;
    }

    long long countPairs(vector<string>& words) {

        unordered_map<string,long long> mp;

        for(string s : words) {

            mp[normalize(s)]++;
        }

        long long ans = 0;

        for(auto &it : mp) {

            long long f = it.second;

            ans += (f * (f - 1)) / 2;
        }

        return ans;
    }
};
