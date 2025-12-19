// //Approach-1 (Recursion+Memo) Similar to LIS - TLE (18 / 25 test cases passed)
// /*
// 	You should always start from an approach like this for 
// 	any DP problem.
// */
// class Solution {
// private:
//     int n, k;
//     unordered_map<string, int> mp;
// public:
//     int solve(vector<int>& nums, int last_chosen_index, int curr_index) {
//         if(curr_index >= n)
//             return 0;
//         string key = to_string(last_chosen_index) + "_" + to_string(curr_index);
        
//         if(mp.find(key) != end(mp))
//             return mp[key];
//         int result = 0;
//         if(last_chosen_index == -1 || curr_index-last_chosen_index <= k) {
//             //take curr_index element
//             int taken = nums[curr_index] + solve(nums, curr_index, curr_index+1);
            
//             //don't take curr_index element
//             int not_taken = solve(nums, -1, curr_index+1);
            
//             result = max(taken, not_taken);
            
// 	}
//         return mp[key] = result;
//     }
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         this->n = nums.size();
//         this->k = k;
        
//         int val = solve(nums, -1, 0);
//         if(val == 0)
//             return -1;
//         return val;
//     }
// };
//Approach-3 (Bottom Up DP) Similar to LIS - TLE
/*
	NOTE : This is basically using the concept of Longest Increasing Subsequence (LIS)
	This can be further improved (from TLE) by using extra data structure. Look for next approaches.
*/
// class Solution {
// public:
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         vector<int> t(n, 0);
//         for(int i = 0; i<n; i++)
//             t[i] = nums[i];
        
//         int maxR = t[0];
        
//         for(int i = 1; i<n; i++) {
//             for(int j = i-1; i-j <= k && j >= 0; j--) {
//                 t[i] = max(t[i], nums[i] + t[j]);
//             }
            
//             maxR = max(maxR, t[i]);
//         }
        
        
//         return maxR;
//     }
// };

//Approach-4 (Using Priority_queue) Accepted
/*
	Basically in Approach-3, you want the maximum value in the range of [i, i-k]
	Why not store them in max heap and access them in one go
*/
class Solution {
public:
    typedef pair<int, int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> t(n, 0);
        t = nums;
        priority_queue<P, vector<P>> pq;
        pq.push({t[0], 0});
        
        int maxR = t[0];
        
        for(int i = 1; i<n; i++) {
            
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            
            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i], i});
            
            maxR = max(maxR, t[i]);
        }
        
        
        return maxR;
    }
};