class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        int i = 1; // index of last valid element

        for(int j = 2; j < n; j++){
            if(nums[j] != nums[i-1]) {  // 👈 key change
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};