class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();

        int l = 0;
        int r = n - 1;

        int ans = 0;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            int h = n - mid;

            if (citations[mid] >= h) {

                ans = h;      // valid h-index
                r = mid - 1;  // try to find bigger h
            } 
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};