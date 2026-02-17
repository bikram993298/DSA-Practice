class Solution {
public:
    string reverseByType(string s) {
        int n=s.size();
        string lower="";
        string special="";
        vector<bool> lower_pre(n,0);

        for(int i=0;i<n;i++){
            if(islower(s[i])){
                lower+=s[i];
                lower_pre[i]=true;
            }else{
                special+=s[i];
            }
        }

        reverse(lower.begin(),lower.end());
        reverse(special.begin(),special.end());

       string ans="";
       int l=0;
       int r=0;
        for(int i=0;i<n;i++){
            if(lower_pre[i]){
                ans+=lower[l];
                l++;

            }else{
                ans+=special[r];
                r++;
            }
            

        }
         return ans;
    //    int l=0;
    //    int n=s.size();
    //    int r=n-1;
    //    while(l<r){
    //     if(islower(s[l]) && islower(s[r])){
    //         swap(s[l],s[r]);
    //         l++;
    //         r--;
    //     }else if(islower(s[l])){
    //         r--;
    //     }else{
    //         l++;
    //     }
    //    }

    //    l=0;
    //     r=n-1;

    //     while(l<r){
    //          if(!islower(s[l]) && !islower(s[r])){
    //         swap(s[l],s[r]);
    //         l++;
    //         r--;
    //     }else if(!islower(s[l])){
    //         r--;
    //     }else{
    //         l++;
    //     }

    //     }

    //     return s;
        
    }
};