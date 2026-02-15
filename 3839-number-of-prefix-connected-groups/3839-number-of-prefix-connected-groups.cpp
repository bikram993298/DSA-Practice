class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n=words.size();
        //apple,apply,hhk,banana,bandit
        //

        map<string,int> mp;

        for(auto word:words){
            string ans="";
            if(word.size()<k) continue;
            for(int j=0;j<k;j++){
                ans+=word[j];
            }
            mp[ans]++;
        }
        int result=0;
        for(auto it:mp){
            if(it.second>1) result++;
        }

        return result;
    }
};