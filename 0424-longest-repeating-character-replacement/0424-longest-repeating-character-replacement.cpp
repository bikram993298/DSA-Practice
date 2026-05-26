// T.C : O(n)
// S.C : O(1)


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;
        // we need valid windor windowsize-maxfreq<=k

        for(int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // if invalid window
            while((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                // update on maxfreq
                maxFreq=0;
                for(int i=0;i<26;i++){
                    maxFreq=max(maxFreq,freq[i]);
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};