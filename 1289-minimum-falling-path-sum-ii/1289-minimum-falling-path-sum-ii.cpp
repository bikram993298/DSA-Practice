class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev = grid[0];

        for (int r = 1; r < n; r++) {

            // find smallest & second smallest in prev row
            int min1 = INT_MAX, min2 = INT_MAX, idx = -1;

            for (int c = 0; c < m; c++) {
                if (prev[c] < min1) {
                    min2 = min1;
                    min1 = prev[c];
                    idx = c;
                } else if (prev[c] < min2) {
                    min2 = prev[c];
                }
            }

            vector<int> cur(m);
            for (int c = 0; c < m; c++) {
                if (c == idx)
                    cur[c] = grid[r][c] + min2;
                else
                    cur[c] = grid[r][c] + min1;
            }

            prev = cur;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
