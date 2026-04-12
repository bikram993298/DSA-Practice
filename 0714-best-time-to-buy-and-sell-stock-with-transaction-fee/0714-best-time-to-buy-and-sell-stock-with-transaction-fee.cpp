// class Solution {
// public:   

// vector<vector<int>> dp;

//     int solve(int i,vector<int>& prices,int fee,int buy){


//         if(i==prices.size()) return 0;


//        int nottake=solve(i+1,prices,fee,buy);
//        int take=0;
//         if(buy==1){
//             take=-prices[i]+solve(i+1,prices,fee,2);

//         }else{
//             take=prices[i]+solve(i+1,prices,fee,1)-fee;
//         }

//         return max(take,nottake);
//     }  
//     int maxProfit(vector<int>& prices, int fee) {
//         int ans=solve(0,prices,fee,1);// 1 for not bought


//         return ans;
        
//     }
// };
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, vector<int>& prices, int fee, int buy) {
        if (i == prices.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        // skip (IMPORTANT FIX: keep same state)
        int nottake = solve(i + 1, prices, fee, buy);

        int take = 0;

        if (buy == 1) {
            // buy stock
            take = -prices[i] + solve(i + 1, prices, fee, 2);
        } else {
            // sell stock
            take = prices[i] - fee + solve(i + 1, prices, fee, 1);
        }

        return dp[i][buy] = max(take, nottake);
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // dp[i][buy], buy = 1 or 2
        dp.assign(n, vector<int>(3, -1));

        return solve(0, prices, fee, 1);
    }
};