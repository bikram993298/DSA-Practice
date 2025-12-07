class Solution {
public:
    long long dp[1001][1001];
    long long min(long long a,long long b){
        if(a<b)return a;
        return b;
    }
    int countPartitions(vector<int>& nums, int k) {
        vector<int>a,b;
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,k,0,0,0);
    }
    
    int solve(int st,vector<int>&nums,int &k,long long sm1,long long sm2,long long mnsm){
        if(st>=nums.size()){
            if(sm1>=k && sm2>=k)return 1;
            return 0;
        }
        if(dp[st][mnsm]!=-1)return dp[st][mnsm];
        
        long long a1=solve(st+1,nums,k,sm1+nums[st],sm2,min(1000,min(sm1+nums[st],sm2)));
        long long a2=solve(st+1,nums,k,sm1,sm2+nums[st],min(1000,min(sm1,sm2+nums[st])));
        
        return dp[st][mnsm]=(a1+a2)%(1000000007);
    }

};