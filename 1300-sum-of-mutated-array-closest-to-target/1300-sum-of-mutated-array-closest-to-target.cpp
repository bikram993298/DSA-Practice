class Solution {
public:
    
    int getSum(vector<int>& arr, int val) {
        int sum = 0;
        
        for (int x : arr) {
            sum += min(x, val);
        }
        
        return sum;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        
        int low = 0;
        int high = *max_element(arr.begin(), arr.end());

        int ans = 0;
        
        while (low <= high) {
            
            int mid = low + (high - low) / 2;
            
            int sum = getSum(arr, mid);
            
            if (sum < target) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        // i am finding the index wggere sum<target ma=in ans where sum<target,,after tha next indx will be greater than sum take minimum of them absolute
        int sum1 = getSum(arr, ans);
        int sum2 = getSum(arr, ans + 1);
        
        if (abs(sum1 - target) <= abs(sum2 - target))
            return ans;
        
        return ans + 1;
    }
};