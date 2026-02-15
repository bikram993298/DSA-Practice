class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        //20->2
        //10->1
        //30->3
        int n=nums.size();
        unordered_map<int,int>mp;

        for( int i=0;i<n;i++){
            mp[nums[i]]++;





        }
        unordered_map<int,int> ma;
        for(auto it:mp){
            ma[it.second]++;
        }

        //2->1
        //1-?1
        //3-?1
        int ans=0;

        for(int i=0;i<n;i++){
           if( ma[mp[nums[i]]]==1){
            ans=nums[i];
            break;
           }
        }
      
        return ans==0?-1:ans;
    }
};