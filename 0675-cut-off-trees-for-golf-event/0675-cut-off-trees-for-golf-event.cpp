class Solution {
public:
    int n,m;
    vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

    int bfs(vector<vector<int>>& forest,int sr,int sc,int tr,int tc) {
        if (sr==tr&&sc==tc) return 0;

        queue<pair<int,int>>q;
        vector<vector<int>>dist(n, vector<int>(m, -1));

        q.push({sr,sc});
        dist[sr][sc] =0;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    forest[nr][nc] != 0 && dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    if (nr == tr && nc == tc)
                        return dist[nr][nc];

                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();

        vector<array<int,3>> trees;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }

        sort(trees.begin(), trees.end());

        int sr =0, sc=0;
        int totalSteps =0;

        for (auto &t : trees) {
            int tr =t[1];
            int tc =t[2];

            int steps=bfs(forest,sr,sc,tr,tc);
            if (steps ==-1) return -1;

            totalSteps += steps;
            sr=tr;
            sc=tc;
        }

        return totalSteps;
    }
};
