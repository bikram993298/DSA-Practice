class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;

        for (char c : word) {
            if (isupper(c)) {
                upperCount++;
            }
        }

        int n = word.size();

        if (upperCount == n) return true;              // all caps
        if (upperCount == 0) return true;              // all small
        if (upperCount == 1 && isupper(word[0])) return true; // only first capital

        return false;
    }
};