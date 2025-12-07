class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        // skip all leading 'L' (they never collide)
        while (i < n && s[i] == 'L') ++i;

        // skip all trailing 'R' (they never collide)
        while (j >= 0 && s[j] == 'R') --j;

        if (i > j) return 0; // no colliding cars left

        int ans = 0;
        // count moving cars ('L' or 'R') in the middle segment [i..j]
        for (int k = i; k <= j; ++k)
            if (s[k] != 'S') ++ans;

        return ans;
    }
};
