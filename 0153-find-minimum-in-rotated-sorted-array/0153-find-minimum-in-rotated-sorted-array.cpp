class Solution {
public:
    int findMin(vector<int>& nums) {
        // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
        
           int start=0;
        int end=nums.size()-1;
       
        while(start<end){
             int mid=start+(end-start)/2;
           
           if(nums[mid]<nums[end]){
                end=mid;
            }
             else{
                start=mid+1;
            }
        }
        return nums[end];
    }
};