class Solution {
public:
    int count = 0;

    void backtrack(int pos, int n, vector<bool>& used) {
        // all positions filled
        if (pos > n) {
            count++;
            // return;
        }

        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % pos == 0 || pos % num == 0)) {
                used[num] = true;

                backtrack(pos + 1, n, used);

                used[num] = false; // backtrack
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        backtrack(1, n, used);
        return count;
    }
};