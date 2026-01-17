class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
         int n=arr.size();
        vector<pair<int,int>> p(n);
       
        for(int i=0;i<n;i++){
            p[i].first=__builtin_popcount(arr[i]);
            p[i].second=arr[i];
        }
        sort(p.begin(),p.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(p[i].second);

        }
        
        return ans;
    }
};