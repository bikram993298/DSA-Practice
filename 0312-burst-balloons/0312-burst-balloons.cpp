class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& nums) {
        if (j - i == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
            // main thing is we have to think the question in reverse roder if u burst i then its burst and ad ts neighbour but dynamicaaly neighbour will change that will hard to tackle so we didi selskt which last burst solve i,j i to j interval not including boudiresies if k burst then all other bewteen i +1 to j-1 bursts,,so numsk * nums[i]* nums[j]

        int finalAns = 0;
        for (int k = i + 1; k < j; k++) {
            int coins = nums[i] * nums[k] * nums[j] + solve(i, k, nums) +
                        solve(k, j, nums);
            finalAns = max(finalAns, coins);
        }
        return dp[i][j] = finalAns;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        /// for my  template  i dont hit first and last items or it was told if edge then consider 1 ,1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        dp.assign(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1, nums);
    }
};
