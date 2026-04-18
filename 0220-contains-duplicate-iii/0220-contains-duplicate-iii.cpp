class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        set<long long> window;

        for (int i = 0; i < nums.size(); i++) {

            long long num = nums[i];
            // for indexing condtion we are maintitimg sliding windorw of eset because we nneds soted and lower bound  now by mathmatics num - t ≤ *it ≤ num + t

            // Find smallest number >= (num - t)
            auto it = window.lower_bound(num - t);

            // Check if it's within range
            if (it != window.end() && *it <= num + t) {
                return true;
            }

            // Insert current
            window.insert(num);

            // Maintain window size
            // k sixe ka ge ka delete
            if (i >= k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};