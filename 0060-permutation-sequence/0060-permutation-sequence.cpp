class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
     vector<int> fact(n);
     fact[0]=1;
     for(int i=1;i<n;i++){
        fact[i]=fact[i-1]*i;
     }

     k--;
     string ans="";
     for(int i=n;i>=1;i--){
        int block=fact[i-1];
        int index=k/block;
        ans+=to_string(nums[index]);
        nums.erase(nums.begin()+index);
        k%=block;
     }
 return ans;


    }
};