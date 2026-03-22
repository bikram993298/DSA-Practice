class Solution {
public:
    int findMin(vector<int>& nums) {
        // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
        
           int start=0;
        int end=nums.size()-1;
 // one of the important problem in binary serach hrere we are finidng only one element so while(l<r) used\
 // always compare with right bcause right part ,, and alwasya discard the sorted part,,a nd end=mid,,remeber       
     
        while(start<end){
             int mid=start+(end-start)/2;
           
           if(nums[end]<nums[mid]){
                start=mid+1;
            }
             else{
              
                end=mid;
            }
        }
        return nums[end];
    }
};