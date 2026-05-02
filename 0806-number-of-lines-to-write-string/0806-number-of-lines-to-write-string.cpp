class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        // widths[s[i]-'a']=widht of that character
        int count=1;
        int curr_l=0;
        int first_w=-1;
        for(int i=0;i<s.size();i++){
            curr_l+=widths[s[i]-'a'];
            if(curr_l>100){
                if(first_w==-1){
                    first_w=curr_l-widths[s[i]-'a'];
                }
                count++;
                curr_l=widths[s[i]-'a'];
            }
           


        }
        return {count,curr_l};
        
    }
};