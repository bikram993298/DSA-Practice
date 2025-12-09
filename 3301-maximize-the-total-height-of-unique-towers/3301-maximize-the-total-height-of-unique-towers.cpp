class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {


        //4 4  3 3 2
        int n=maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        int maxi=maximumHeight[0]-1;

        for(int i=1;i<n;i++){
            maxi=min(maxi,maximumHeight[i]-1);
            if(maximumHeight[i]==maximumHeight[i-1]){
                maximumHeight[i]=maxi;

            }




        }
        long long ans=0;
        for(int i=0;i<n;i++){
            cout<<maximumHeight[i];
            ans+=maximumHeight[i];
        }


        return (maximumHeight[n-1]==0)?-1:ans;

    }
};