class Solution {
public:

    bool isVowel(char ch) {

        return ch=='a' || ch=='e' ||
               ch=='i' || ch=='o' ||
               ch=='u';
    }

    int maxVowels(string s, int k) {

        int n = s.size();

        int vowels = 0;

        int ans = 0;

        int left = 0;

        for(int right = 0; right < n; right++) {

            // include current character
            if(isVowel(s[right])) {
                vowels++;
            }

            // maintain fixed window size
            if(right - left + 1 > k) {

                // remove left character
                if(isVowel(s[left])) {
                    vowels--;
                }

                left++;
            }

            // valid window of size k
            if(right - left + 1 == k) {

                ans = max(ans, vowels);
            }
        }

        return ans;
    }
};