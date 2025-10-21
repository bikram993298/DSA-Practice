class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) parent[a] = b;
    }
};

class Solution {
public:
    int n;
    vector<int> dir = {0, 1, 0, -1, 0};

    bool canReach(vector<vector<int>>& grid, int mid) {
        DSU dsu(n * n);
        auto id = [&](int i, int j){ return i * n + j; };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > mid) continue;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dir[d], nj = j + dir[d+1];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] <= mid)
                        dsu.unite(id(i,j), id(ni,nj));
                }
            }
        }
        return dsu.find(0) == dsu.find(n*n - 1);
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = 0, high = n*n - 1, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canReach(grid, mid)) {
                ans = mid;
                high = mid - 1;  // try smaller t
            } else {
                low = mid + 1;   // need more time
            }
        }
        return ans;
    }
};
