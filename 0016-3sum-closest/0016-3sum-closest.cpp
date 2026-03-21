class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = 100000000;

        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;

            while(l < r){
                int sum = a[i] + a[l] + a[r];

                if(abs(target - sum) < abs(target - ans))
                    ans = sum;

                if(sum < target) l++;
                else if(sum > target) r--;
                else return sum;
            }
        }
        return ans;
    }
};