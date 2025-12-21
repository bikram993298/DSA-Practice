class Solution {
public:
    #define ll long long
    vector<vector<vector<long long>>> dp;

    int n;
    long long solve(int i,int k,vector<int>& nums,bool start_new){

        if(k==0){
            return 0;
        }
        if(i>=n) return LLONG_MIN/4;


        if(dp[i][k][start_new]!=LLONG_MIN){
            return dp[i][k][start_new];
        }





        ll not_take=LLONG_MIN;
        ll take;
        if(start_new==true){
            not_take=solve(i+1,k,nums,start_new);
        }

        ll sign=(k%2!=0?1:-1);
        take=solve(i+1,k,nums,false)+sign*nums[i]*k;
        take=max(take,solve(i+1,k-1,nums,true)+sign*nums[i]*k);


        return dp[i][k][start_new]=max(not_take,take);



    }
      
    long long maximumStrength(vector<int>& nums, int k) {
        ll ans=0;
        n=nums.size();
        dp.resize(n+1,vector<vector<ll>>(k+1,vector<ll>(2,LLONG_MIN)));
        bool start_new=true;


      return  solve(0,k,nums,start_new);
        
    }
};