class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l=0,r=tokens.size()-1;
        int ans=0;
        int score=0;

        while(l<=r){
            if(power>=tokens[l]){
                 power -= tokens[l];
                score++;
                l++;
                ans=max(ans,score);
            }else if(score>0){
                score--;
              
                power+=tokens[r];
                  r--;
            }else{
                break;
            }

        }

        return ans;
        
    }
};