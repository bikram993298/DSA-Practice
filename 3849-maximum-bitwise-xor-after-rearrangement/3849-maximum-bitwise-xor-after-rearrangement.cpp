class Solution {
public:
    string maximumXor(string s, string t) {
        
        int count1=0,count0=0;
        
        for(char c : t){
            if(c=='1')count1++;
            else count0++;
        }
        
        string ans="";
        
        for(char c : s){
            
            if(c=='0'){
                if(count1 > 0){
                    ans+= '1';
                    count1--;
                }else{
                    ans+='0';
                    count0--;
                }
            }
            else{ 
                //c=='1'
                if(count0 > 0){
                    ans+='1';
                    count0--;
                }else{
                    ans+='0';
                    count1--;
                }
            }
        }
        
        return ans;
    }
};