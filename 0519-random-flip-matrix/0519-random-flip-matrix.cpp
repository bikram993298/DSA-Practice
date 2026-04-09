class Solution {
    int rows, cols;
    int remaining;
    unordered_map<int, int> mp;

public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
        remaining = m * n;
    }

    vector<int> flip() {
        //pick random index
        int r = rand() % remaining;

        //  find actual value at r
        int actualIndex;
        if (mp.find(r) != mp.end()) {
            actualIndex = mp[r];
        } else {
            actualIndex = r;
        }

        // find last available value
        int lastIndex;
        if (mp.find(remaining - 1) != mp.end()) {
            lastIndex = mp[remaining - 1];
        } else {
            lastIndex = remaining - 1;
        }

        // Step 4: move last value to position r
        mp[r] = lastIndex;

        // Step 5: reduce available size
        remaining--;

        // Step 6: convert to 2D
        return {actualIndex / cols, actualIndex % cols};
    }

    void reset() {
        mp.clear();
        remaining = rows * cols;
    }
};