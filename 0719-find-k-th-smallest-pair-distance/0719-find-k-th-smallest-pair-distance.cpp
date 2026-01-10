class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int max_element = 0;

        for(int i=0;i<n;i++)
        {
            max_element = max(max_element,nums[i]);
        }

        vector<int> pair_diff(max_element +1 ,0);

        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int diff = abs(nums[i]-nums[j]);
                pair_diff[diff] +=1;
            }
        }


        for(int i=0;i<max_element+1;i++)
        {
            k -= pair_diff[i];
            if(k <= 0)
            {
                return i;
            }
        }

        return 0;
    }
};