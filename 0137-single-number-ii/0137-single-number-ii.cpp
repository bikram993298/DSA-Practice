class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32);
        for (int x: nums) {
            for (int i = 0; i < 32;i++) {
                if (x&(1<<i)) cnt[i]++;
            }
        }

        int num = 0;
        for (int i = 0; i< 32;i++) {
            if (cnt[i] % 3 != 0) num |= (1 << i);
        }
        return num;
    }
};