class Solution {
public:
    int ans = 0;

    bool isSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    void solve(vector<int>& nums, vector<bool>& used, vector<int>& path) {
        
        if (path.size() == nums.size()) {
            ans++;
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // your required code start from here

            if (used[i]) continue;

            // skip duplicates
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;

            // check square condition
            if (!path.empty() && !isSquare(path.back() + nums[i]))
                continue;

            // your required code end here

            used[i] = true;
            path.push_back(nums[i]);

            solve(nums, used, path);

            path.pop_back();
            used[i] = false;
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> path;

        solve(nums, used, path);

        return ans;
    }
};