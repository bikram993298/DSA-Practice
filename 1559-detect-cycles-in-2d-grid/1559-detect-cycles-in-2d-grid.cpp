class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    bool dfs(vector<vector<char>>& grid, int x, int y,
             int px, int py, char ch) {
        
        vis[x][y] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // boundary check
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            // only same character allowed
            if (grid[nx][ny] != ch)
                continue;

            // parent node skip
            if (nx == px && ny == py)
                continue;

            // already visited => cycle found
            if (vis[nx][ny])
                return true;

            if (dfs(grid, nx, ny, x, y, ch))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};