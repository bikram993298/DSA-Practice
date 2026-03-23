class Solution {
public:
//left to right then top+1 to down then rught +1 to lwft then down-1 to top+1 then shrink all boundaries..
//endge case it during traversal of left to rught at bottom if top==down then skip one traversal

// //Current complexity:
// 𝑂
// (
// 𝑀
// ∗
// 𝑁
// )
// O(M∗N)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) 
            return {};
// main thing you in on eiteration you hvae to go left to roght hten top+1 to down then right+1 to left then down-1 to top+1,,then left++,right--,top++,down-- ,, herer a speacial check thath during trversla  if think row is single then and somehow top and bootm have smae after some traversal you have gone left to right  then in noraml case u will agian add right to left thaat is duplicate so one time check same for down to top check left== right single c oloumn
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> result;
        int top = 0, down = n - 1;
        int left = 0, right = m - 1;

        while (top <= down && left <= right) {
            // 1) Left → Right on the top row
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }

            // 2) Top+1 → Down on the right column
            for (int i = top + 1; i <= down; ++i) {
                result.push_back(matrix[i][right]);
            }

            // 3) Right-1 → Left on the bottom row
            for (int i = right - 1; i >= left; --i) {
                if (top == down) break;  // avoid retraversal when single row remains
                result.push_back(matrix[down][i]);
            }

            // 4) Down-1 → Top+1 on the left column
            for (int i = down - 1; i > top; --i) {
                if (left == right) break;    // avoid retraversal when single row remains
                result.push_back(matrix[i][left]);
            }

            // shrink boundaries
            ++top;
            --down;
            ++left;
            --right;
        }

        return result;
    }
};
