class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int ans = 0;
// main idea msintain prev how many o or 1 ,then if you find different then min of prev and current will give u substringm,,do the last pre,count will be unmatched beacuse wghen u reach last for loop khtatam no else confition so add extra
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                curr++;
            } else {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        ans += min(prev, curr);

        return ans;
    }
};