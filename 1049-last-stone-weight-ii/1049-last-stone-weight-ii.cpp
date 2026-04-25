class Solution {
public:
    int solve(int i, int curr, int target, vector<int>& stones, vector<vector<int>>& dp) {
        if(i == stones.size()) {
            return curr;
        }

        if(dp[i][curr] != -1) return dp[i][curr];

        int take = 0;

        // take current stone if within limit
        if(curr + stones[i] <= target) {
            take = solve(i + 1, curr + stones[i], target, stones, dp);
        }

        // skip current stone
        int skip = solve(i + 1, curr, target, stones, dp);

        return dp[i][curr] = max(take, skip);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int x : stones) sum += x;

        int target = sum / 2;

        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, -1));

        int best = solve(0, 0, target, stones, dp);

        return sum - 2 * best;
    }
};