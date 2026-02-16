class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       deque<int> maxi, mini;

        int n=nums.size();
        long long total=1LL*n*(n+1)/2;
        // our idea is to calclute no of subtring that less than k
        int l=0;
        long long cnt=0;
        for(int i=0;i<n;i++){
          while(!maxi.empty() && nums[maxi.back()]<=nums[i]){
            maxi.pop_back();
          }
          maxi.push_back(i);
           while(!mini.empty() && nums[mini.back()]>=nums[i]){
            mini.pop_back();
          }
          mini.push_back(i);


          while(l<=i &&(long long)(i-l+1)*(nums[maxi.front()]-nums[mini.front()])>k){
            cnt+=n-i;
            if(maxi.front() == l)
                    maxi.pop_front();

                if(mini.front() == l)
                    mini.pop_front();
            l++;





            
          }










        }
        return (total-cnt);
        
    }
};