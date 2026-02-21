class Solution {
public:

    string normalize(string s) {

        int shift = s[0] - 'a';

        string res;

        for(char c : s) {
// like we have implemented to become all string to come in same stansdrad make all first a then how much to make a subtract that,somehow if substraction becones -shift modulo by 26 becuase it was told that z before a
            res.push_back((c - shift ) % 26 + 'a');
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
