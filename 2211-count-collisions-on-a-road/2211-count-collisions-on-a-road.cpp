class Solution {
public:
    int countCollisions(string s) {
        stack<char> st;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                st.push(s[i]);
            }else if(s[i]=='S'){
                if(!st.empty()){
                    ans=ans+1;

                    st.pop();
                }
            }else{
                if(!st.empty()){
                    if(st.top()!='S'){
                        ans=ans+2;
                        st.pop();
                        st.push('S');
                    }else{
                        ans=ans+1;
                        st.pop();
                        st.push('S');
                    }
                    
                }
            }
        }


        return ans;
        
    }
};