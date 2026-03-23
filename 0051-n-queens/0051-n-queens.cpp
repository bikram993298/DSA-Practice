class Solution {
public:
   vector<vector<string>> result;
  

   bool check(int p,int q,vector<string>&temp){
            int n=temp.size();
            int m=temp[0].size();
          for(int i=0;i<n;i++){
            if(temp[i][q]=='Q') return false;
          }
         for(int j=0;j<m;j++){
            if(temp[p][j]=='Q') return false;

         }
         int x=p;
         int y=q;
         while(x>=0&& y>=0){
            if(temp[x][y]=='Q') return false;
            x--;
            y--;
         }
         x=p;
         y=q;
          while(x<n-1&& y<n-1){
           
            x++;
            y++;
             if(temp[x][y]=='Q') return false;
         }
          x=p;
         y=q;
          while(x>=0&& y<n){
            if(temp[x][y]=='Q') return false;
            x--;
            y++;
         }
          x=p;
         y=q;
          while(x<m&& y>=0){
            if(temp[x][y]=='Q') return false;
            x++;
            y--;
         }
       
       return true;
   }
   void solve(int i,int n, vector<string>&temp){

    if(i==n){
        result.push_back(temp);
        return;
    }



   
        for(int j=0;j<temp[i].size();j++){
            if(check(i,j,temp)){
                 temp[i][j]='Q';
            solve(i+1,n,temp);
                temp[i][j]='.';

            }
          
           
        }


    
     return;
    
   }

    vector<vector<string>> solveNQueens(int n) {
         vector<string> temp;
         string s = "";
         for (int i = 0; i < n; i++) s += '.';
         for (int i = 0; i < n; i++) temp.push_back(s);

    solve(0,n,temp);


    return result;


        
    }
};