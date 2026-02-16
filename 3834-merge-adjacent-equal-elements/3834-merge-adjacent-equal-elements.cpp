class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long > st;
        for(int i=0;i<n;i++){
            long long comp=nums[i];
            while(!st.empty() && st.top()==comp){
                // int top=st.top();
                st.pop();
                // st.push(2*nums[i]);
                comp=2*comp;
            }
                st.push(comp);
            

            


        }
        vector<long long > ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        

        // cout<<ans<<endl;
        return ans;
    }
};