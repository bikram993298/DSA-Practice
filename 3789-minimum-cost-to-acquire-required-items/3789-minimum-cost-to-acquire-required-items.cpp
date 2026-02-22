class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

//216
//,
long long cost=0;
   if(need1>need2){
  cost=cost1;
   }else{
    cost=cost2;
   }
   long long option1=1LL*costBoth*min(need1,need2)+1LL*(max(need1,need2)-1LL*min(need1,need2))*cost;


        return min({1LL*cost1*need1+1LL*cost2*need2,1LL*costBoth*max(need1,need2),option1});
        
    }
};