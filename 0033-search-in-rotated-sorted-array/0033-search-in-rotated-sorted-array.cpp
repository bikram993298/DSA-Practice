class Solution {
public:
// memory find pivot use binary searach 0 to pivot and pivto+1 to nthe find neccesary index
    int minimum(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    
    int binary_search(vector<int>& nums, int l, int r, int target) {
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = minimum(nums);

       
        
        
         int idx = binary_search(nums, pivot, n-1, target);
        if(idx != -1)
            return idx;
        idx = binary_search(nums, 0, pivot-1, target);
        return idx;
    }
};