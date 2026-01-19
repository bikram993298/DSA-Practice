class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        // must be power of 2 (only one set bit)
        if((n & (n - 1)) != 0) return false;
        Example:
// 16 = 10000
// 15 = 01111
// AND → 00000 ✅

        // that bit must be at even position
        return (n & 0x55555555) != 0;
    }
};
