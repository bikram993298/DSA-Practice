class Solution {
public:
      const int MOD=1e9+7;


    int specialTriplets(vector<int>& nums) {
        map<int,long long>r_mp;
        map<int,long long>l_mp;
        for(int i=1;i<nums.size();i++){
            r_mp[nums[i]]++;
        }

        //6->2
        //3->1
        long long ans=0;
        
         l_mp[nums[0]]++;
        for(int i=1;i<nums.size();i++){
             r_mp[nums[i]]--;

            if(r_mp.count(2*nums[i]) && l_mp.count(2*nums[i])) {
                
                ans=ans+r_mp[2*nums[i]]*l_mp[2*nums[i]];
            }
            l_mp[nums[i]]++;
            
            

        }


         return (ans%MOD+MOD)%MOD;
    }
};