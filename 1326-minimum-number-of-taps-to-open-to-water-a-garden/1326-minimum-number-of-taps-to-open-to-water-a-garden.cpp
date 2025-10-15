class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxre(n+1, 0);
        // build max reach from each left index
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            maxre[left] = max(maxre[left], right);
        }

        int taps = 0;
        int end = 0;      // end of current coverage (we have guaranteed coverage up to 'end')
        int farther = 0;  // farthest we can reach while scanning within the current segment

        for (int i = 0; i <= n; i++) {
            if (i > farther) return -1;                // can't reach position i
            farther = max(farther, maxre[i]);         // extend farthest reachable using intervals starting at i
            if (i == end) {                            // we've reached the end of current coverage segment
                taps++;
                end = farther;                         // jump to the farthest we can reach
                if (end >= n) return taps;             // if we've covered to n, return result early
            }
        }

        return -1; // (shouldn't be reached because loop either returns or detects unreachable)
    }
};
