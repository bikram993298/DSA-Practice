class Solution {
public:

    bool check(vector<int>& nums, long long k){

        long long cnt = 0;

        for(int x : nums){

            cnt += (x + k - 1) / k;

            if(cnt > k * k)
                return false;
        }

        return cnt <= k * k;
    }

    int minimumK(vector<int>& nums) {

        long long l = 1;
        long long r = 1e9;
        long long ans = r;

        while(l <= r){

            long long mid = l + (r - l) / 2;

            if(check(nums, mid)){

                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
