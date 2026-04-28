class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // street type -> allowed directions
        unordered_map<int, vector<pair<int,int>>> dir = {
            {1, {{0,-1}, {0,1}}},
            {2, {{-1,0}, {1,0}}},
            {3, {{0,-1}, {1,0}}},
            {4, {{0,1}, {1,0}}},
            {5, {{0,-1}, {-1,0}}},
            {6, {{0,1}, {-1,0}}}
        };

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return true;
            }

            int type = grid[x][y];

            for (auto [dx, dy] : dir[type]) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (vis[nx][ny])
                    continue;

                int nextType = grid[nx][ny];

                // verify next cell connects back
                for (auto [rdx, rdy] : dir[nextType]) {
                    if (nx + rdx == x && ny + rdy == y) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
};