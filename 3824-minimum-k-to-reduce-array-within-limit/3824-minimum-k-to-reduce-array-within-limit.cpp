class Solution {
public:

     bool check(vector<int>& nums,int mid){
        int cnt=0;
        int mi=nums[mid];
        for(int i=0;i<nums.size();i++){
            cnt+=ceil((double)(nums[i])/mid);
        }

        cout<<cnt<<endl;


        return (1LL*cnt<=1LL*mid*mid);
     }
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        
        int l=1;
        int r=INT_MAX;
        int ans=nums[0];
        while(l<=r){

            // int mid=(l+r)/2;
            int mid=l+(r-l)/2;
            if(check(nums,mid)){
                ans=mid;
                r=mid-1;


            }else{
                l=mid+1;
                
            }
        }

        return ans;
        
    }
};