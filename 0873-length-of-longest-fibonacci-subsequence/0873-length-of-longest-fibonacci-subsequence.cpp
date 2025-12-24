// class Solution {
// public:
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         int maxLen = 0;

//         for (int curr = 2; curr < n; curr++) {
//             int start = 0, end = curr - 1;
//             while (start < end) {
//                 int pairSum = arr[start] + arr[end];
//                 if (pairSum > arr[curr]) {
//                     end--;
//                 } else if (pairSum < arr[curr]) {
//                     start++;
//                 } else {
//                     dp[end][curr] = dp[start][end] + 1;
//                     maxLen = max(dp[end][curr], maxLen);
//                     end--;
//                     start++;
//                 }
//             }
//         }
//         return maxLen == 0 ? 0 : maxLen + 2;
//     }
// };
class Solution {
public:
    unordered_map<int, int> index;   // value -> index
    vector<vector<int>> memo;
    int n;

    int solve(int i, int j, vector<int>& arr) {
        if (memo[i][j] != -1)
            return memo[i][j];

        int next = arr[i] + arr[j];

        // If next value doesn't exist, sequence ends
        if (!index.count(next))
            return memo[i][j] = 0;

        int k = index[next];
        if (k <= j)
            return memo[i][j] = 0;

        // Extend the sequence
        return memo[i][j] = 1 + solve(j, k, arr);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        memo.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            index[arr[i]] = i;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, solve(i, j, arr));
            }
        }

        return ans == 0 ? 0 : ans + 2;
    }
};
