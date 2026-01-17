// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int>ans;
//         for(int i=0;i<=n;i++){
//             int count=__builtin_popcount(i);
//             ans.push_back(count);
//             cout<<count;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> result;
        result.push_back(0);
        
        for(int i=0;i<=n;i++){
            if(i%2==0 &&i!=0){
              result.push_back(result[i/2]);

            }else if(i%2!=0 && i!=0){
                result.push_back(result[i/2]+1);
            }

        }  
        return result;      
    }
};

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> result(n + 1, 0);  // Initialize vector with size n + 1 and default value 0

//         for (int i = 1; i <= n; ++i) {
//             // If i is even, number of 1s is the same as i/2
//             if (i % 2 == 0) {
//                 result[i] = result[i / 2];
//             } else {  // If i is odd, number of 1s is 1 more than i/2
//                 result[i] = result[i / 2] + 1;
//             }
//         }

//         return result;
//     }
// };