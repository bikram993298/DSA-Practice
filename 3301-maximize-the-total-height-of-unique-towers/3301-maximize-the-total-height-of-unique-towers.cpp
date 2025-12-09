class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        if (n == 0) return -1;             // no heights -> keep consistent with your -1 convention

        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());

        // Build the maximum strictly-decreasing sequence from left to right
        long long ans = 0;
        int curr = maximumHeight[0];       // allowed value for position 0

        // position 0
        maximumHeight[0] = curr;
        ans += maximumHeight[0];

        for (int i = 1; i < n; ++i) {
            // next allowed value is at most curr-1, and also cannot exceed maximumHeight[i]
            curr = min(curr - 1, maximumHeight[i]);
            if (curr < 0) curr = 0;        // ensure non-negative heights

            maximumHeight[i] = curr;
            ans += maximumHeight[i];
        }

        // preserve your original convention: if last height is 0 return -1, else sum
        return (maximumHeight[n - 1] == 0) ? -1 : ans;
    }
};
