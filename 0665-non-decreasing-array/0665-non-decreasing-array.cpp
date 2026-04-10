class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
// just simply chekinh breaking points will not give result because here ryou are not swapping you are chning one point like [3, 4, 2, 3]
// so here 1 break,,point ans is false,,because you will make ehere rberak fails to nums[i+1] equal to maximize the chnc ebutagain check it previous elemnt is smaller than this
// 6 5 4 3
//
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                cnt++;
                // 1 s ejda dhoga to fail to hogayi..but 1 hokweb hi fail ho skata he
                if (cnt > 1) return false;

                if (i == 0 || nums[i-1] <= nums[i+1]) {
                    nums[i] = nums[i+1]; // lower current
                } else {
                    nums[i+1] = nums[i]; // raise next
                }
            }
        }

        return true;
    }
};