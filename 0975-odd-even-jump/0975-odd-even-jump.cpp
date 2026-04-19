// Time: O(N log N)
// Space: O(N)

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<bool> odd(n, false), even(n, false);
        odd[n-1] = even[n-1] = true;
        
        map<int, int> mp; // value -> index
        mp[arr[n-1]] = n-1;
        
        int ans = 1; // last index always valid
        
        for (int i = n - 2; i >= 0; i--) {
            
            // ODD jump
            auto it1 = mp.lower_bound(arr[i]);
            if (it1 != mp.end()) {
                odd[i] = even[it1->second];
            }
            
            // EVEN jump
            auto it2 = mp.upper_bound(arr[i]);
            if (it2 != mp.begin()) {
                it2--;
                even[i] = odd[it2->second];
            }
            
            if (odd[i]) ans++;
            
            mp[arr[i]] = i;
        }
        
        return ans;
    }
};