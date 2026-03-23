class Solution {
public:
    vector<int> dp;

    int solve(int i, int n) {
        if(i == n) return 1;
        if(i > n) return 0;

        if(dp[i] != -1) return dp[i];
        int ans=0;
        ans+= solve(i+1, n) ;
        ans+=solve(i+2, n);

       

        return dp[i] = ans;
    }

    int climbStairs(int n) {
        dp.assign(n+1, -1);
        return solve(0, n);
    }
};