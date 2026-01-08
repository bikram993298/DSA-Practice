// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
//         for (auto &row : image) {
//             int l = 0, r = row.size() - 1;

//             while (l <= r) {
//                 int temp = row[l] ^ 1;
//                 row[l] = row[r] ^ 1;
//                 row[r] = temp;
//                 l++;
//                 r--;
//             }
//         }
//         return image;
//     }
// };


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto &row : image) {

            // Step 1: reverse the row
            int l = 0, r = row.size() - 1;
            while (l < r) {
                swap(row[l], row[r]);
                l++;
                r--;
            }

            // Step 2: invert the bits
            for (int &bit : row) {
                bit = bit ^ 1;
            }
        }
        return image;
    }
};
