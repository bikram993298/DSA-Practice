class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (int x : arr1) {
            // first element >= x - d
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);

            // check if this eleme > dnt lies within [x-d, x+d]
            if (it == arr2.end() || *it > x + d) {
                       ans++;
               }

        }
        return ans;
    }
};
// 4 5 8
// 1 8 9 10 