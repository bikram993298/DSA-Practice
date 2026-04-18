class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int swappedPrev, vector<int>& nums1, vector<int>& nums2) {
        
        if (i == n) return 0;

        if (dp[i][swappedPrev] != -1) return dp[i][swappedPrev];

        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
/// if u swap real elents if array chnages in the array,thne after recusion you hvae to revrese swa p that,,becuase her ecomes backtracking so 2^n cmes so it is imposisible so use swpped ale that indicates previous is swapped or not ,,if you want to swap then swap the prev 2 that will correct the code ,,and start recusuion from oth 1 index one swap or another not swap ,,form xero i have to perv elemnts
        // If previous was swapped, reverse them
        if (swappedPrev) {
            swap(prev1, prev2);
        }

        int ans = INT_MAX;

        // 🔹 Option 1: No swap
        if (nums1[i] > prev1 && nums2[i] > prev2) {
            ans =min(ans, solve(i+1, 0, nums1, nums2));
        }

        // 🔹 Option 2: Swap
        if (nums1[i] > prev2 && nums2[i] > prev1) {
            ans = min(ans, 1 + solve(i+1, 1, nums1, nums2));
        }

        return dp[i][swappedPrev] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp.assign(n, vector<int>(2, -1));

        // Try both starting possibilities
        return min(
            solve(1, 0, nums1, nums2),        // no swap at 0
            1 + solve(1, 1, nums1, nums2)     // swap at 0
        );
    }
};