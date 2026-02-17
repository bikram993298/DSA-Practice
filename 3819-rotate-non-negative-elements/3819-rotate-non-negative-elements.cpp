class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> non;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>=0) non.push_back(nums[i]);
        }
        // 1 3
        vector<int> rotate(non.size());
        for(int i=0;i<non.size();i++){
            rotate[i]=non[(i+k)%non.size()];


        }
        //3 1
        int l=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0)nums[i]=rotate[l++];
        }

        return nums;
        
    }
};