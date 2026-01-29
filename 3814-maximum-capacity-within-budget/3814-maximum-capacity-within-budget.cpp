class Solution {
public:
  
   int check(int target,int index,vector<pair<int,int>>& p){

    int l=0;
    int h=index-1;
  
    int ans=-1;
    while(l<=h){
          int mid=(l+h)/2;
          if(p[mid].first>target){
        h=mid-1;
    }else{
        ans=mid;
        l=mid+1;
    }


    }
  

    return ans;
    
   }

    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
// aslodalodloda
//
        //3 4 5 8
        // 7 2 1 5
        //3 8 4 5
        //7 5 2 1
        //5 4 8 3
        // 1 2 5 7
        // 3 4  5 8
      
        int n=capacity.size();
          vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++){
            p[i].first=costs[i];
            p[i].second=capacity[i];

        }

       sort(p.begin(),p.end());
       vector<int> pre(n,0);
       pre[0]=p[0].second;
       for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],p[i].second);

       }

    //    for(int i=0;i<n;i++){
    //     cout<<pre[i]<<endl;
    //    }
    int nas=INT_MIN;
// 4 8 5 3
// 1 5 2 7

// 3 4 5 8
// 7 1 2 5

// 4 6
// 5 3
// 3
   for(int i=0;i<n;i++){
    if(p[i].first<budget){
         nas=max(nas,p[i].second);
        
    }
   
   }
    for(int i=1;i<n;i++){
        if (p[i].first >= budget) break;
        int target=budget-p[i].first-1;
        // if(target<0) continue; 
        int b=check(target,i,p);
        if(b==-1){
         
            continue;
        }
// cout << b << endl;
        int num=pre[b];

        nas=max(nas,p[i].second+num);
    } 

        return nas==INT_MIN?0:nas;
    }
};