class Solution {
public:
  vector<vector<long long>> dp;
   long long solve(int i,int j,string & s,string & t){


    if(j==t.size())return 1;
    if(i==s.size())return 0;
      if (dp[i][j] != -1) return dp[i][j];
   long long ans=0;
    if(s[i]==t[j]){
        long long take=solve(i+1,j+1,s,t);
        long long notake=solve(i+1,j,s,t);
        ans=take+notake;

    }else{
         long long notake=solve(i+1,j,s,t);
         ans=notake;

    }

     return dp[i][j] = ans;
   }
    int numDistinct(string s, string t) {

dp.assign(s.size(), vector<long long>(t.size(), -1));
        int ans=solve(0,0, s, t);

        return ans;
        
    }
};