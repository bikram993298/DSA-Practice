// //Approach-2 (Recursion + Memo with 1-D Memo) - Time Limit Exceeded
// class Solution {
// public:
//     int n;
//     int D;
//     int t[100001];
//     int solve(int idx, vector<int>& arr) {
        
//         if(t[idx] != -1)
//             return t[idx];
        
//         int result = 0;
        
//         for(int i = idx+1; i < n; i++) {
//             int prevVal = arr[idx];
//             int currVal = arr[i];


//             if (currVal - prevVal == D)
//                 result = max(result, 1 + solve(i, arr));
//         }
        
//         return t[idx] = result;
//     }
    
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int result = 0;
//         n = arr.size();
//         D = difference;
        
//         memset(t, -1, sizeof(t));
        
//         for (int i = 0; i < n; i++) {
//             result = max(result, 1 + solve(i, arr));
//         }

//         return result;
//     }
// };


//Approach-3 (DP using Map) - O(n) - Accepted
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int n = arr.size();
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            
            int prev            = arr[i] - difference;
            
            int lengt_till_prev = mp[prev];
            
            mp[arr[i]] = lengt_till_prev + 1;
            
            result = max(result, mp[arr[i]]);
        }
        
        return result;
    }
};