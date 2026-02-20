// class Solution {
// public:




//    int solve(int i,bool flag,int target1,int target2,vector<int> & nums, vector<int> prefix){
//      // base case
     
//      int num=prefix(i);
//      //give xor value till i
//      if(i==n  ){
//         if(flag){
//             if(num==target1){
//                   return 1;
//             }{
//                 return 0;
//             }

//         }else{
//             if(num==target2){
//                   return 1;
//             }else{
//                 return 0;

//             }
//         }
      
//      }

//      return num+solve(i+1,!flag,target1,target2,nums,prefix);





//    }
//     int alternatingXOR(vector<int>& nums, int target1, int target2) {

//         bool flag=true;
//         vector<int> prefix(n);
// prefix[0] = arr[0];

// for(int i = 1; i < n; i++) {
//     prefix[i] = prefix[i-1] ^ arr[i];
// }
//         // true meansstarge1 is conintuueoing
//     int ans=solve(0,flag,target1,target2,nums,prefix);
//     rerturn ans;
        
//     }
// };
// class Solution {
// public:
    
//     const int MOD = 1e9 + 7;
//     int n;
//     int t1, t2;
//     vector<long long> px;
    
//     unordered_map<long long, long long> memo;
    
//     long long solve(int index, int lastSplit, bool isT1Turn) {
        
//         if(index == n) {
//             // Check final block
//             long long blockXor =
//                 (lastSplit == -1 ? px[n-1]
//                                  : px[n-1] ^ px[lastSplit]);
            
//             if(isT1Turn && blockXor == t1) return 1;
//             if(!isT1Turn && blockXor == t2) return 1;
//             return 0;
//         }
        
//         // Encode state
//         long long key =
//             ((long long)index << 32) |
//             ((long long)(lastSplit + 1) << 1) |
//             (isT1Turn ? 1LL : 0LL);
        
//         if(memo.count(key))
//             return memo[key];
        
//         long long ans = 0;
        
//         // Compute current block XOR
//         long long blockXor =
//             px[index] ^ (lastSplit == -1 ? 0 : px[lastSplit]);
        
//         // Option 1: do NOT cut
//         ans = solve(index + 1, lastSplit, isT1Turn) % MOD;
        
//         // Option 2: cut here if valid
//         if(isT1Turn && blockXor == t1) {
//             ans = (ans + solve(index + 1, index, false)) % MOD;
//         }
        
//         if(!isT1Turn && blockXor == t2) {
//             ans = (ans + solve(index + 1, index, true)) % MOD;
//         }
        
//         return memo[key] = ans;
//     }
    
    
//     int alternatingXOR(vector<int>& nums, int target1, int target2) {
        
//         n = nums.size();
//         t1 = target1;
//         t2 = target2;
        
//         px.resize(n);
//         px[0] = nums[0];
//         for(int i = 1; i < n; i++)
//             px[i] = px[i-1] ^ nums[i];
        
//         memo.clear();
        
//         return solve(0, -1, true);
//     }
// };
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        const int MOD = 1e9 + 7;

        unordered_map<int, long long> mp1, mp2;
        mp1[0] = 1;

        long long x = 0, count1 = 0, count2 = 0;

        for (int num : nums) {
            x ^= num;

            int t1 = x ^ target1;
            int t2 = x ^ target2;

            count1 = mp2.count(t2) ? mp2[t2] : 0;
            count2 = mp1.count(t1) ? mp1[t1] : 0;

            mp1[x] = (mp1[x] + count1) % MOD;
            mp2[x] = (mp2[x] + count2) % MOD;
        }

        return (count1 + count2) % MOD;
    }
};