class Solution {
public:

    bool valid(vector<int>& need, vector<int>& window) {

        for(int i = 0; i < 128; i++) {

            if(window[i] < need[i]) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for(char ch : t) {
            need[ch]++;
        }

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            // expand window
            window[s[right]]++;

            // shrink while valid
            while(valid(need, window)) {

                if(right - left + 1 < minLen) {

                    minLen = right - left + 1;
                    start = left;
                }

                // remove left
                window[s[left]]--;

                left++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};