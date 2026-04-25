// class Solution {
// public:
//     int n, m;
// //     int original;

// //     int dx[4] = {-1, 1, 0, 0};
// //     int dy[4] = {0, 0, -1, 1};

// //     void dfs(int x, int y, vector<vector<int>>& grid,
// //              vector<vector<int>>& vis, int color) {

// //         vis[x][y] = 1;

// //         int sameColorNeighbours = 0;

// //         for (int k = 0; k < 4; k++) {
// //             int nx = x + dx[k];
// //             int ny = y + dy[k];

// //             if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
// //                 grid[nx][ny] == original) {

// //                 sameColorNeighbours++;

// //                 if (!vis[nx][ny]) {
// //                     dfs(nx, ny, grid, vis, color);
// //                 }
// //             }
// //         }

// //         // if not surrounded from all 4 sides → border
// //         if (sameColorNeighbours < 4) {
// //             grid[x][y] = color;
// //         }
// //     }

// //     vector<vector<int>> colorBorder(vector<vector<int>>& grid,
// //                                     int row, int col, int color) {

// //         n = grid.size();
// //         m = grid[0].size();

// //         original = grid[row][col];

// //         vector<vector<int>> vis(n, vector<int>(m, 0));

// //         dfs(row, col, grid, vis, color);

// //         return grid;
// //     }
// // };




// Your code fails because of this line:

// ```cpp id="z5b8wz"
// grid[x][y] = color;
// ```

// done **during DFS itself**.

// That causes a problem.

// ---

// # Why Wrong Answer Happens

// Testcase:

// ```cpp id="p7ksn1"
// grid =
// [[1,1,1],
//  [1,1,1],
//  [1,1,1]]

// row = 1
// col = 1
// color = 2
// ```

// Expected:

// ```cpp id="rj4cxr"
// [[2,2,2],
//  [2,1,2],
//  [2,2,2]]
// ```

// Only border should change.

// Center should remain `1`.

// ---

// # What your DFS does

// Suppose DFS reaches border first:

// ```cpp id="sxsk9f"
// (0,1)
// ```

// and changes it to:

// ```cpp id="1hwhn5"
// 2
// ```

// Now when DFS comes back to center:

// ```cpp id="mlaflq"
// (1,1)
// ```

// it checks neighbors.

// But now one neighbor is:

// ```cpp id="wkg8uy"
// 2 instead of 1
// ```

// So it thinks:

// > this is also border

// which is wrong.

// Then center also gets colored.

// That is why whole grid becomes `2`.

// ---

// # Core Issue

// You are modifying grid while still using it for checking.

// This breaks DFS logic.

// ---

// # Correct Fix

// Do NOT change color immediately.

// Instead:

// ### Step 1

// Find border cells first

// ---

// ### Step 2

// After DFS ends

// color only those border cells

// ---

// # Standard Fix

// Use temporary mark like:

// ```cpp id="r5l1jv"
// -1
// ```

// or store border cells separately.

// ---

// # Clean Fix Code

// ```cpp id="tzwjlwm"
class Solution {
public:
    int n, m;
    int original;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int x, int y, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        vis[x][y] = 1;

        int sameColorNeighbours = 0;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                abs(grid[nx][ny]) == original) {

                sameColorNeighbours++;

                if (!vis[nx][ny]) {
                    dfs(nx, ny, grid, vis);
                }
            }
        }

        // mark border temporarily
        if (sameColorNeighbours < 4) {
            grid[x][y] = -original;
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                    int row, int col, int color) {

        n = grid.size();
        m = grid[0].size();

        original = grid[row][col];

        vector<vector<int>> vis(n, vector<int>(m, 0));

        dfs(row, col, grid, vis);

        // final coloring
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -original) {
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }
};
// ```

// ---

// # Interview Line

// Say:

// > We must not recolor during DFS because later cells depend on original values for border checking.
// > So I first mark border cells temporarily and recolor them afterward.
