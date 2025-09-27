class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int l=0;
        int r=0;
        int len=0;
        //increase r
        //while loop till you shrink you get false infomrtiaon
        //out the while loop it is true and you can update the len
        while(r<s.size()){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
                if(mp[s[l]]==0) mp.erase(s[l]);
            }
             len=max(len,r-l+1);
            r++;
             

            
           
        }
       
        
        return len;
    }
};