class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;
        int roof = total; // virtual roof node
        DSU dsu(total + 1);

        auto id = [&](int i, int j) { return i * m + j; };

        vector<vector<int>> copy = grid;
        // Step 1: Mark all hits
        for (auto &h : hits) {
            int r = h[0], c = h[1];
            if (copy[r][c] == 1) copy[r][c] = 0;
        }

        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

        // Step 2a: Process top row first and connect bricks to roof
        for (int j = 0; j < m; ++j) {
            if (copy[0][j] == 1) {
                dsu.unite(id(0, j), roof);
                for (auto &d : dir) {
                    int ni = 0 + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && copy[ni][nj] == 1)
                        dsu.unite(id(0,j), id(ni,nj));
                }
            }
        }

        // Step 2b: Process the rest of the grid
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (copy[i][j] == 1) {
                    for (auto &d : dir) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && copy[ni][nj] == 1)
                            dsu.unite(id(i,j), id(ni,nj));
                    }
                }
            }
        }

        // Step 3: Process hits in reverse
        vector<int> ans(hits.size(), 0);
        for (int k = hits.size() - 1; k >= 0; --k) {
            int r = hits[k][0], c = hits[k][1];
            if (grid[r][c] == 0) continue;

            int prevRoofSize = dsu.getSize(roof);

            // Add brick back
            copy[r][c] = 1;

            // Connect to neighbors
            for (auto &d : dir) {
                int ni = r + d[0], nj = c + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && copy[ni][nj] == 1)
                    dsu.unite(id(r,c), id(ni,nj));
            }

            // Connect to roof if in top row
            if (r == 0) dsu.unite(id(r,c), roof);

            int newRoofSize = dsu.getSize(roof);
            ans[k] = max(0, newRoofSize - prevRoofSize - 1);
        }

        return ans;
    }
};
