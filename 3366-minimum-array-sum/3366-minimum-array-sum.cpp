class Solution {
public:
    int ceilDiv(int x) {
        return (x + 1) / 2;
    }

  
    vector<vector<vector<int>>> dp;

    int solve(vector<int>& nums, int i, int k, int op1, int op2) {
        if (i == nums.size()) return 0;
        int &ans = dp[i][op1][op2];
        if (ans != -1) return ans;

        ans = INT_MAX;
        int val = nums[i];

       
        ans = min(ans, val + solve(nums, i + 1, k, op1, op2));

        
        if (op1 > 0) {
            ans = min(ans, ceilDiv(val) + solve(nums, i + 1, k, op1 - 1, op2));
        }

       
        if (op2 > 0 && val >= k) {
            ans = min(ans, (val - k) + solve(nums, i + 1, k, op1, op2 - 1));
        }

       
        if (op1 > 0 && op2 > 0) {
        
            if (val >= k) {
                ans = min(ans, ceilDiv(val - k)
                       + solve(nums, i + 1, k, op1 - 1, op2 - 1));
            }
           
            int d = ceilDiv(val);
            if (d >= k) {
                ans = min(ans, (d - k)
                       + solve(nums, i + 1, k, op1 - 1, op2 - 1));
            }
        }

        return ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        dp.assign(n + 1,
                  vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return solve(nums, 0, k, op1, op2);
    }
};
