class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0); //O(K)
        //mp[r] = x
        //remainder r has frequency x

        for(int &num : arr) {
            int rem = (num%k + k) % k; //handling negative remainders
            mp[rem]++;
        }
// edge case 5 se pura devisble numbbers shoul be in even,,bcause you cant to do by  k-rem
        if(mp[0] % 2 != 0) {
            return false;
        }

        for(int rem = 1; rem <= k/2; rem++) {
            int counterHalf = k - rem;
            if(mp[counterHalf] != mp[rem]) {
                return false;
            }
        }

        return true;
    }
};