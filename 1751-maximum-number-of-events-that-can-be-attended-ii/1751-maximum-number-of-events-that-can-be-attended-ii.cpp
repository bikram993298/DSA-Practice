class Solution {
public:
    int n;
    vector<vector<int>> dp;

    // Binary search for next event whose start > current event's end
    int nextEventIndex(vector<vector<int>>& events, int i) {
        int left = i + 1, right = n - 1, ans = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > events[i][1]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& events, int i, int k) {
        if (i >= n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        // Option 1: skip current event
        int skip = solve(events, i + 1, k);

        // Option 2: take current event
        int nextIdx = nextEventIndex(events, i);
        int take = events[i][2] + solve(events, nextIdx, k - 1);

        return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        n = events.size();
        dp.assign(n, vector<int>(k + 1, -1));
        return solve(events, 0, k);
    }
};
