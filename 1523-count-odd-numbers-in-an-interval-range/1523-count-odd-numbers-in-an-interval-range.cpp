class Solution {
public:
    int countOdds(int low, int high) {
        // 3,5,7,
        // int ans=(high-low)/2;
        // if(low%2!=0) ans++;
        // if(high%2!=0) ans++;
        int ans=0;
        if(low%2!=0 && high%2!=0){
            ans=2+(high-low)/2 -1;
        }else if(low%2!=0 && high%2==0){
            ans=1+(high-low)/2;
        }else if(low%2==0 && high%2!=0){
            ans=1+(high-low)/2;
        }else if(low%2==0 && high%2==0){
            ans=(high-low)/2;
        }


        return ans;
     }
};