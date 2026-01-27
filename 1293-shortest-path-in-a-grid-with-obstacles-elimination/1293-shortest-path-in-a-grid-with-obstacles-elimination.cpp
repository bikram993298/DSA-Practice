class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<bool>>> visited(
              n, vector<vector<bool>>(m, vector<bool>(k + 1, false))
        );

        queue<tuple<int,int,int>> q;
        // row, col, remaining k
        q.push({0, 0, k});
        visited[0][0][k] = true;

        int steps = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int sz = q.size(); 

            while (sz--) {
                auto [x, y, rem] = q.front();
                q.pop();

                
                if (x == n - 1 && y == m - 1)
                    return steps;

                for (auto &d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx <0||ny<0 || nx >= n||ny >= m) continue;

                    int nk = rem - grid[nx][ny];
                    // just add x ,y another ermanining it is greedy bfs like ehwe en in levle you findin obastactel make k-- and chekkc k>= 0 then addd adjacent
                    if (nk >= 0 && !visited[nx][ny][nk]) {
                        visited[nx][ny][nk] = true;
                        q.push({nx, ny, nk});
                    }
                }
            }

            steps++; 
        }

        return -1;
    }
};
