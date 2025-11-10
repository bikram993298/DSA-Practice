class Solution {
public:
//most optimisedapproach
    int removeDuplicates(vector<int>& nums) {
       //we will start form othe and 1st index
       int i=0;
       for(int j=1;j<nums.size();j++){
        if(nums[j]!=nums[i]){

            nums[++i]=nums[j];
        }
       }
        
        return i+1;
        //i gives index so i+1 no
    }
};
//0,0,1,1,1,2,2,3,3,4
//i=0,j=1
//