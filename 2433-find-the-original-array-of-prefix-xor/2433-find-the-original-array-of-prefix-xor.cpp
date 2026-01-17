class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int> ans(n);
        ans[0]=pref[0];
    
        for(int i=1;i<n;i++){
            ans[i]=pref[i]^pref[i-1];
        }
        return ans;
        
    }
};
//tc=o(n)
//sc=o(n)

// below is more like space effcient more so we need pref[i-1] and pref[i] so go from n-1 to 0 ,,,
// and like prefixsum ans[i]=prefixsem[i]^prefixsum[i-1]


// class Solution {
// public:
//     vector<int> findArray(vector<int>& pref) {
//         int n=pref.size();
    
//         for(int i=n-1;i>0;i--){
//             pref[i]=pref[i]^pref[i-1];
//         }
//         return pref;
        
//     }
// };