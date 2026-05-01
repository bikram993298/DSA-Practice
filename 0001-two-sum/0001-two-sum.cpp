class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // //o(nlogn)
        // // sapce o(n)
        //    int n=nums.size();
        // vector<pair<int,int>> p;
        // for(int i=0;i<n;i++){
        //     p.push_back({nums[i],i});
        // }
        // sort(p.begin(),p.end());
     
        // int l=0,r=n-1;
        // while(l<r){
        //     int sum=p[l].first+p[r].first;
        //     if(sum==target) return {p[l].second,p[r].second};
        //     if(sum>target){

        //         r--;
        //     }else{
        //         l++;
        //     }
        // }
        // return {-1,-1};
        int n=nums.size();

        map<int,int>mp;
        //i=target-j
        for(int i=0;i<n;i++){
            if(mp.count(target-nums[i])){
                return {i,mp[target-nums[i]]};
            }
            //mp[3]=0;
            //mp[2]=1;

            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};