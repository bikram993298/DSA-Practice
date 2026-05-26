class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

        unordered_map<string,int> count;

        vector<int> freq(26, 0);

        int distinct = 0;

        int left = 0;

        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            // include current character
            if(freq[s[right] - 'a'] == 0) {
                distinct++;
            }

            freq[s[right] - 'a']++;

            // maintain fixed window size
            if(right - left + 1 > minSize) {

                freq[s[left] - 'a']--;

                if(freq[s[left] - 'a'] == 0) {
                    distinct--;
                }

                left++;
            }

            // valid window
            if(right - left + 1 == minSize) {

                if(distinct <= maxLetters) {

                    string sub = s.substr(left, minSize);

                    count[sub]++;

                    ans = max(ans, count[sub]);
                }
            }
        }

        return ans;
    }
};