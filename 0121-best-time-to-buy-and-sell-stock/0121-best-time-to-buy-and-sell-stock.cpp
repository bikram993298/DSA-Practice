class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> rightmax(n,0);
        rightmax[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],prices[i+1]);
            cout<<rightmax[i]<<endl;
        }

        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,rightmax[i]-prices[i]);
        }
        return ans;
    }
};