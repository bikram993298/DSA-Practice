class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
        vector<vector<int>> ans;
        queue<pair<int,int>> q;

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        q.push({rCenter, cCenter});
        vis[rCenter][cCenter] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            ans.push_back({x, y});

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 &&
                    nx < rows && ny < cols &&
                    vis[nx][ny] == 0) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};