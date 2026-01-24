class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        vector<bool> used(26,false);
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(used[c-'a'])continue;
            while(!st.empty() && st.top()>c && last[st.top()-'a']>i){
                used[st.top()-'a']=false;
                st.pop();
            }
            st.push(c);
            used[c-'a']=true;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};