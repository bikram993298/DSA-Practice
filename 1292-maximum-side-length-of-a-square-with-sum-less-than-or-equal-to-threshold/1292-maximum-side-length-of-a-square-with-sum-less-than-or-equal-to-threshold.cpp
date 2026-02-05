// class Solution {
// public:
//     int maxSideLength(vector<vector<int>>& mat, int threshold) {
//         int m=mat.size();
//         int n=mat[0].size();

//         vector<vector<int>> pref(m + 1,vector<int>(n+1, 0));

        
//         for (int i=1; i<=m;i++) {
//             for (int j=1; j<=n; j++) {
//                 pref[i][j] = mat[i-1][j-1] + pref[i-1][j]+ pref[i][j -1]- pref[i-1][j-1];
//             }
//         }

//         int ans=0;

//         // there is a cathc htht o c hec k all possible square staring from thaht posiiton you have to create offser of isze
//         for (int len=1; len<=min(m,n);len++) {
//             for (int i=0;i+len<=m;i++) {
//                 for (int j=0;j+len<=n;j++) {

//                     int sum = pref[i+len][j+len]
//                             - pref[i][j+len]
//                             - pref[i+len][j]
//                             + pref[i][j];

//                     if (sum<=threshold) {
//                         ans=len;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };


// // O(m * n * min(m, n))
// always in 2d prefissum use 1 based iindexing like if you eant osme till 3,3 index inr eal,,we have to get(4,4) in prefisum  hope you got

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // prefix sum array
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        int low = 0, high = min(m, n);
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            bool ok = false;

            for (int i = 0; i + mid <= m; i++) {
                for (int j = 0; j + mid <= n; j++) {
                    int sum = pref[i + mid][j + mid]
                            - pref[i][j + mid]
                            - pref[i + mid][j]
                            + pref[i][j];

                    if (sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }

            if (ok) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
