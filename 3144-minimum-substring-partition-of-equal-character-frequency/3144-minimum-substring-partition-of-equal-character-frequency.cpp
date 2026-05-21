class Solution {
public:

    int dp[1001];

    bool balanced(vector<int>& freq) {

        int val = 0;

        for(int x : freq) {

            if(x == 0)
                continue;

            if(val == 0)
                val = x;

            else if(val != x)
                return false;
        }

        return true;
    }

    int solve(int i, string& s) {

        int n = s.size();

        // base case
        if(i == n)
            return 0;

        // memoization
        if(dp[i] != -1)
            return dp[i];

        vector<int> freq(26, 0);

        int ans = 1e9;

        // try every substring
        for(int j = i; j < n; j++) {

            freq[s[j] - 'a']++;

            // if balanced
            if(balanced(freq)) {

                ans = min(ans,
                          1 + solve(j + 1, s));
            }
        }

        return dp[i] = ans;
    }

    int minimumSubstringsInPartition(string s) {

        memset(dp, -1, sizeof(dp));

        return solve(0, s);
    }
};