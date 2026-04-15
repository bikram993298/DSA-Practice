class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        // count frequency of s
        for(char c : s) {
            freq[c - 'a']++;
        }

        string result = "";

        // place characters in order
        for(char c : order) {
            while(freq[c - 'a'] > 0) {
                result += c;
                freq[c - 'a']--;
            }
        }

        // add remaining characters
        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                result += (char)(i + 'a');
                freq[i]--;
            }
        }

        return result;
    }
};