class Solution {
public:
    int residuePrefixes(string s) {
        
        map<char,int>mp;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(mp.size()==(i+1)%3)cnt++;
        }
        return cnt;
    }
};