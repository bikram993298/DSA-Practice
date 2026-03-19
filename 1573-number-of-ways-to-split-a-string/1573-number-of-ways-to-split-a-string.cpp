// class Solution {
// public:
//     const long long MOD = 1e9 + 7;
//     int n, k;
//     vector<int> prefix;
//     vector<vector<long long>> memo;

//     long long solve(int index, int parts) {
        
//         // If we formed 3 parts
//         if(parts == 3) {
//             return (index == n) ? 1 : 0;
//         }
        
//         // If reached end but not 3 parts
//         if(index == n) return 0;

//         if(memo[index][parts] != -1)
//             return memo[index][parts];

//         long long ways = 0;

//         // Try making a cut at every possible end
//         for(int end = index; end < n; end++) {
            
//             int ones = prefix[end+1] - prefix[index];

//             if(ones == k) {
//                 ways = (ways + solve(end+1, parts+1)) % MOD;
//             }
//         }

//         return memo[index][parts] = ways;
//     }

//     int numWays(string s) {

//         n = s.size();
//         int total = 0;

//         for(char c : s)
//             if(c == '1') total++;

//         // All zero case
//         if(total == 0) {
//             long long ways = (long long)(n-1)*(n-2)/2;
//             return ways % MOD;
//         }

//         if(total % 3 != 0) return 0;

//         k = total / 3;

//         // Build prefix sum
//         prefix.assign(n+1, 0);
//         for(int i = 0; i < n; i++)
//             prefix[i+1] = prefix[i] + (s[i] == '1');

//         memo.assign(n+1, vector<long long>(4, -1));

//         return solve(0, 0);
//     }
// };



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