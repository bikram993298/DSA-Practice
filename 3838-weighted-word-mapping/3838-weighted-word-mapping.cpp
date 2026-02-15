class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string result="";

        for(auto word:words){

            int ans=0;
            for(int j=0;j<word.size();j++){
                ans+=weights[word[j]-'a'];
                 cout<<weights[word[j]-'a']<<endl;
              


            }
            cout<<ans<<endl;
             
            result+=(25-(ans%26))+'a';

        }
        return result;
    }
};