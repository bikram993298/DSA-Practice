class Solution {
public:
    long long rev(int n){
        int ans=0;
        // 1021
        // 1201
        //1200->
       while(n>0){
        ans=ans*10+n%10;
        n=n/10;

       }
       cout<<ans<<endl;
       return ans;

    }
    int minMirrorPairDistance(vector<int>& nums) {
        
        int n=nums.size();
        map<long long,int>mp;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            long long x=rev(nums[i]);
            if(mp.find(x)!=mp.end()){
                //cout<<mp[x]<<","<<i<<endl;
               ans=min(ans,abs(i-mp[x])); 
            }
           
            mp[nums[i]]=i;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};