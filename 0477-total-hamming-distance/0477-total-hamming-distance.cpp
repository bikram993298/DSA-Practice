class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int bit = 0; bit < 32; bit++) {
            long long ones = 0;

            for(int num : nums) {
                if(num & (1 << bit)) ones++;
            }

            long long zeros = n - ones;
            ans += ones * zeros;
        }

        return (int)ans;
    }
};


// Binary:

// 4 = 0100

// 14 = 1110

// 2 = 0010

// Check bit1:
// ones = 2 (14 and 2)
// zeros = 1 (4)
// contribution = 2*1 = 2

// Sum all bits → answer = 6