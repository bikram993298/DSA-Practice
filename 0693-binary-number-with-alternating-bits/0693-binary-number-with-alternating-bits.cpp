class Solution {
public:
    bool hasAlternatingBits(int n) {
        long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;  // ✅ x+1 safe now, no overflow
    }
};