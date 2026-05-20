class Solution {
public:
    map<vector<int>, int> dp;

    int solve(vector<int>& price, vector<vector<int>>& special,
              vector<int>& needs) {

        // memoization
        if (dp.count(needs))
            return dp[needs];

        int n = price.size();

        // buy everything directly
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += needs[i] * price[i];
        }

      
        for (auto& offer : special) {

            vector<int> remaining = needs;

            bool valid = true;
           // check that do nto creoos the needs so for loop to chekc valid offer or not
            // check if offer can be applied
            for (int i = 0; i < n; i++) {

                if (offer[i] > remaining[i]) {
                    valid = false;
                    break;
                }

                remaining[i] -= offer[i];
            }

            // if valid use it
            if (valid) {
                // try all vlaid offers and recurse

                ans = min(ans, offer[n] + solve(price, special, remaining));
            }
        }

        return dp[needs] = ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                       vector<int>& needs) {

        return solve(price, special, needs);
    }
};