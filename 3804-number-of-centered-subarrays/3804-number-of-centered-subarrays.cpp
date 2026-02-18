class Solution {
public:


    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();


        int cnt=0;
        vector<int > prefix(n + 1,0);

    // prefix[0] = 0;

  for(int i = 1; i <= n; i++) {
    prefix[i] = prefix[i-1] + nums[i-1];
}

        for(int i=0;i<n;i++){
              set<int> st;
            for(int j=i;j<n;j++){
              
                // st.insert(nums[i]);
                st.insert(nums[j]);
                int sum=prefix[j+1]-prefix[i];
                if(st.count(sum))cnt++;

            }
        }
        return cnt;
    }
};