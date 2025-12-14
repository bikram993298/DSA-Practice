class Solution {
public:
    int n;
    int t[1001][1003];
    
    int solve(vector<int>& nums, int i, int diff) {
        
        if(i == n-1)
            return 0;
        
        if(t[i][diff+501] != -1)
            return t[i][diff+501];
        
        int ans = 0;
        
        for(int k = i+1; k<n; k++) {
            
            if(nums[k] - nums[i] == diff)
                ans = max(ans, 1 + solve(nums, k, diff));
            
        }
        
        return t[i][diff+501] = ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        if(n <= 2)
            return n;
        
        memset(t, -1, sizeof(t));
        
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j < n; j++) {
                
                result = max(result, 1 + solve(nums, i, nums[j] - nums[i]));
                
            }
        }
        
        return result;
    }
};
//in brute force use two for loop i 0 to n and j i+1 to n ,,then agagin k from j+1 to n ,if diff equal len++,,count maximum lent,,,,
//in recursion what we do we pass solve by index and avalable diff,then  again for loop i+1 to n checl diff equal again recursivel  call solve,,if i>n return 0 ,,,but complexcity n^3,,so bottom up,,here is memo trick that diff can be negative and diff can be upto 500,so in -500 can also happen to initialie dp state +5001 to remove negative