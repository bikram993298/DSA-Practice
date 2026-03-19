class Solution {

public:
//    int solve(string s,int i,int k){

//     // base cond



//    }


   
    int numWays(string s) {

        // int ans=solve(s,0,3);

        // return ans;

   const long long MOD=1e9+7;


        int total_1=0;
        for(int i=0;i<s.size();i++){

            if(s[i]=='1')total_1++;
        }
         if(total_1 == 0){
            long long n = s.size();
            return ((n-1)*(n-2)/2) % MOD;
        }


        if(total_1%3!=0) return 0;
        total_1=total_1/3;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;
            if(cnt==total_1){
                cnt=i;
                break;
            }
        }
       int cnt_0=0;
       cnt++;
        while(cnt<s.size()&&s[cnt]=='0'){
          cnt++; 
            cnt_0++;
        }
         cnt=0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1') cnt++;
            if(cnt==total_1){
                cnt=i;
                break;
            }



        }



         int cnt_0l=0;
         cnt--;
        while(cnt>=0&&s[cnt]=='0'){
            // if(s[cnt++]=='1'){
            //     break;

            // }
            cnt--;
            cnt_0l++;
        }



        return ((long long)(cnt_0+1)*(1+cnt_0l))%MOD;
    }
};
//111           0101010         111