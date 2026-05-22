class Solution {
public:

    bool possible(vector<int>& nums, int threshold, int d) {

        int sum = 0;

        for(int num : nums) {

            sum += ceil((double)num / d);

            if(sum > threshold)
                return false;
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        int ans = r;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(possible(nums, threshold, mid)) {

                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};