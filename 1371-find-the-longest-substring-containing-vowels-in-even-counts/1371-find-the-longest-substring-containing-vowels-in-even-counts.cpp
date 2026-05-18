class Solution {
public:
    int findTheLongestSubstring(string s) {

        unordered_map<int, int> firstIndex;

        // all vowels even initially
        //i will not slidin window because it dows not monotonic,,i will like two sum in mask aeiou has 00000 has 0 all means even no of occurenrces,,,,00001 means u has odd ocucurences and all other are even occurences,, you have tackled 1010 and agian got same 101 menas middle aprt haseven occurences
        firstIndex[0] = -1;

        int mask = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // toggle vowel parity
            if (ch == 'a')
                mask ^= (1 << 0);

            else if (ch == 'e')
                mask ^= (1 << 1);

            else if (ch == 'i')
                mask ^= (1 << 2);

            else if (ch == 'o')
                mask ^= (1 << 3);

            else if (ch == 'u')
                mask ^= (1 << 4);

            // same mask seen before
            if (firstIndex.count(mask)) {

                ans = max(ans, i - firstIndex[mask]);

            } else {

                // store first occurrence only
                firstIndex[mask] = i;
            }
        }

        return ans;
    }
};