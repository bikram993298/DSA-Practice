class Solution {
public:
    string largestEven(string s) {
        int n=s.size();
        string ans="";
        bool flag=false;
        for(int i=n-1;i>=0;i--){
            if(s[i]!='2' &&flag){
                ans=ans+s[i];
            }
            if(s[i]=='2'){
                flag=true;
                ans=ans+s[i];
            }
        }
        cout<<ans<<endl;
        reverse(ans.begin(),ans.end());

        return ans;
    }
};