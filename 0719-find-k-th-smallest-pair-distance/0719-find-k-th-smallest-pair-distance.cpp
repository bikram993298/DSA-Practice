// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         int max_element = 0;

//         for(int i=0;i<n;i++)
//         {
//             max_element = max(max_element,nums[i]);
//         }

//         vector<int> pair_diff(max_element +1 ,0);

//         for(int i=0;i<n;i++)
//         {
//             for(int j = i+1;j<n;j++)
//             {
//                 int diff = abs(nums[i]-nums[j]);
//                 pair_diff[diff] +=1;
//             }
//         }


//         for(int i=0;i<max_element+1;i++)
//         {
//             k -= pair_diff[i];
//             if(k <= 0)
//             {
//                 return i;
//             }
//         }

//         return 0;
//     }
// };
class Solution {
public:
    int countPair(vector<int>& nums , int diff)
    {
        int n = nums.size();
        int i=0;
        int j = i+1;
        int countAllPair = 0;
        while(i < n && j<n)
        {
            if(abs(nums[i] -nums[j]) <= diff)
            {
                countAllPair += (j-i);
                j++;
            }else
            {
                i++;   
            }
        }

        return countAllPair;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int low = 0;
        int high = abs(nums[0] - nums[n-1]);
        int ans = 0;

        while(low <= high)
        {
            int mid = (low + high)/2;

            int count = countPair(nums , mid);

            if(count < k)
            {
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }


        return ans;
    }
};