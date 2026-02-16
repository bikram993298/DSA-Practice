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
