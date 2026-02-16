// // class Solution {
// //   vector<vector<vector<long long>>> dp;





// // public:



// //        long long solve(int i,int j,vector<int>& nums1,vector<int> & nums2,int k){
// //         // base case

// //         if(k==0){
// //             return 0;
// //         }
// //         if(i>=nums1.size() || j>=nums2.size()) return LLONG_MIN;




// //         // int take=0;

// //        long long take = LLONG_MIN;

// //      for(int m=j;m<nums2.size();m++){

// //         long long next=solve(i+1,m+1,nums1,nums2,k-1);
// //         if(next!=LLONG_MIN){
// //              take = max(take,1LL * nums1[i] * nums2[m] +solve(i+1,m+1,nums1,nums2,k-1)
// //     );

// //         }
   
// // }

// //         long long nottake=solve(i+1,j,nums1,nums2,k);




// //         return max(take,nottake);




// //        }
// //     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

// //       dp.resize(nums1.size(),vector<int>(nums2.size(),))
// //         long long ans=solve(0,0,nums1,nums2,k);
// //         return ans;
        
// //     }
// // };
// class Solution {

//     vector<vector<vector<long long>>> dp;

//     const long long NEG = LLONG_MIN / 2;

// public:

//     long long solve(int i,int j,
//                     vector<int>& nums1,
//                     vector<int>& nums2,
//                     int k){

//         if(k == 0)
//             return 0;

//         if(i >= nums1.size() || j >= nums2.size())
//             return NEG;

//         if(dp[i][j][k] != NEG)
//             return dp[i][j][k];

//         long long take = NEG;

//         for(int m=j; m<nums2.size(); m++){

//             long long next =
//                 solve(i+1,m+1,nums1,nums2,k-1);

//             if(next != NEG)
//                 take = max(take,
//                     1LL * nums1[i] * nums2[m] + next);
//         }

//         long long nottake =
//             solve(i+1,j,nums1,nums2,k);

//         return dp[i][j][k] = max(take,nottake);
//     }

//     long long maxScore(vector<int>& nums1,
//                        vector<int>& nums2,
//                        int k){

//         int n = nums1.size();
//         int m = nums2.size();

//         dp.assign(n,
//             vector<vector<long long>>(m,
//                 vector<long long>(k+1, NEG)));

//         return solve(0,0,nums1,nums2,k);
//     }
// };
// o(n3*k) time limit exceed
class Solution {
public:

    long long NEG = LLONG_MIN/2;
    vector<vector<vector<long long>>> dp;
    int n,m;

    long long solve(int i,int j,int k,
                    vector<int>& nums1,
                    vector<int>& nums2){

        if(k==0)
            return 0;

        if(n-i < k || m-j < k)
            return NEG;

        if(dp[i][j][k]!=NEG)
            return dp[i][j][k];

        long long skip1 =
            solve(i+1,j,k,nums1,nums2);

        long long skip2 =
            solve(i,j+1,k,nums1,nums2);

        long long take =
            1LL*nums1[i]*nums2[j] +
            solve(i+1,j+1,k-1,nums1,nums2);

        return dp[i][j][k] =
            max({skip1,skip2,take});
    }

    long long maxScore(vector<int>& nums1,
                       vector<int>& nums2,
                       int k){

        n = nums1.size();
        m = nums2.size();

        dp.assign(n+1,
            vector<vector<long long>>(m+1,
                vector<long long>(k+1,NEG)));

        return solve(0,0,k,nums1,nums2);
    }
};
