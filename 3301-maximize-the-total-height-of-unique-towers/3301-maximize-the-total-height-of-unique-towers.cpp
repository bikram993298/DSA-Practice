class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
    
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());

       long long ans = 0;
        int curr = maximumHeight[0];     
       
        ans += maximumHeight[0];

        for (int i = 1; i < n; ++i) {
        
            curr = max(0,min(curr - 1, maximumHeight[i]));
         

            maximumHeight[i] = curr;
           
        }

        for(int i=1;i<n;i++){
            ans+=maximumHeight[i];
        }
        return (maximumHeight[n - 1] == 0) ? -1 : ans;
    }
};
