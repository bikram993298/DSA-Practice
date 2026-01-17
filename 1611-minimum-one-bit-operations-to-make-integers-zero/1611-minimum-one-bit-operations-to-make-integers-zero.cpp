class Solution {
public:
    int minimumOneBitOperations(int n) {
        // we have to iterate from n-1 to 0 or whaterver then if i  got 1 then 2 power i+1 -1  i have to plus then if i find agaain 1 then minize that contribution then again add
 int ans=0;
 bool flag=true;
    for(int i=31;i>=0;i--){
        if(n&1<<i){
            if(flag){
                ans+=(1<<i+1)-1;

            }else{
                ans-=(1<<i+1)-1;
            }
            
            flag=!flag;

        }

    }


        return ans;
    }
};