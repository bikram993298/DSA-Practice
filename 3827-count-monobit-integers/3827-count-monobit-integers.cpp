class Solution {
public:
    int countMonobit(int n) {

        int count = 1; // include 0

        long long x = 1;

        while(x<=n) {
            count++;
            x = (x<<1)|1;
        }

        return count;
    }
};

//  How (x << 1) | 1 works

// Example:

// x = 1   → 1
// x = 3   → 11
// x = 7   → 111
// x = 15  → 1111


// Each step adds one more 1 bit.
