class Solution {
public:

    bool check(vector<int>& a, vector<int>& b) {

        for(int i = 0; i < 26; i++) {

            if(a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

        int n = s2.size();
        int k = s1.size();

        if(k > n) return false;

        // frequency of s1
        vector<int> freq1(26, 0);

        for(char ch : s1) {
            freq1[ch - 'a']++;
        }

        // sliding window frequency
        vector<int> window(26, 0);

        int left = 0;

        for(int right = 0; right < n; right++) {

            // include current character
            window[s2[right] - 'a']++;

            // maintain fixed window size
            if(right - left + 1 > k) {

                window[s2[left] - 'a']--;

                left++;
            }

            // valid window
            if(right - left + 1 == k) {

                // permutation found
                if(check(freq1, window)) {

                    return true;
                }
            }
        }

        return false;
    }
};