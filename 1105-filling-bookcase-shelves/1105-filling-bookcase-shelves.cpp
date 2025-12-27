class Solution {
public:
    int n, W;
    vector<int> dp;

    int solve(int i, vector<vector<int>>& books) {
    
        if (i == n) return 0;

       
        if (dp[i] != -1) return dp[i];

        int width = 0;
        int maxHeight = 0;
        int ans = INT_MAX;

        // try placing i..j on the samf
        for (int j = i; j < n; j++) {
            width += books[j][0];
            if (width > W) break;

            maxHeight = max(maxHeight, books[j][1]);
            ans = min(ans, maxHeight + solve(j + 1, books));
        }

        return dp[i] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        W = shelfWidth;
        dp.assign(n, -1);
        return solve(0, books);
    }
};
