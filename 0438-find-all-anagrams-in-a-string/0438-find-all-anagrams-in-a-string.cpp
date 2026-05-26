class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {

        for (int i = 0; i < 26; i++) {

            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int k = p.size();

        vector<int> ans;

        // pattern frequency
        vector<int> pfreq(26, 0);

        for (char ch : p) {
            pfreq[ch - 'a']++;
        }

        // sliding window frequency
        vector<int> window(26, 0);

        int left = 0;

        for (int right = 0; right < n; right++) {

            // include current character
            window[s[right] - 'a']++;

            // maintain fixed window size
            if (right - left + 1 > k) {

                window[s[left] - 'a']--;

                left++;
            }

            // valid window
            // if (right - left + 1 == k) {

                // compare frequencies
                if (check(window, pfreq)) {

                    ans.push_back(left);
                }
            // }
        }

        return ans;
    }
};