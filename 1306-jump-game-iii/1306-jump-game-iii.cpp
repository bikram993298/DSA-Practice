class Solution {
public:

    vector<int> dp;
    vector<int> vis;

    bool solve(vector<int>& arr, int idx) {

        // out of bounds
        if(idx < 0 || idx >= arr.size())
            return false;

        // found zero
        if(arr[idx] == 0)
            return true;

        // cycle
        if(vis[idx])
            return false;

        // already computed
        if(dp[idx] != -1)
            return dp[idx];

        vis[idx] = 1;

        int left = idx - arr[idx];
        int right = idx + arr[idx];

        bool ans = solve(arr, left) || solve(arr, right);

        vis[idx] = 0;

        return dp[idx] = ans;
    }

    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        dp.assign(n, -1);
        vis.assign(n, 0);

        return solve(arr, start);
    }
};