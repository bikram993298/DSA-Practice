class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            //  j isno nzero wit we are swapping with other '
            // when we got nonzero swap then onmly j increase

            if(nums[i] != 0) {

                swap(nums[i], nums[j]);

                j++;
            }
        }
    }
};