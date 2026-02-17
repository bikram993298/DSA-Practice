// class Solution {
// public:
// // i did this thinking substring
// //    bool check_zero(vector<int>& cnt){

// //      bool flag=true;
// //      for(int i=0;i<cnt.size();i++){
// //         if(cnt[i]!=0) flag=false;
// //      }

// //      return flag;

// //    }

// //    void add(vector<int>& cnt,int number){

// //     for(int i=0;i<32;i++){
// //         if(!(number&1<<i)){
// //             cnt[i]++;
// //         }
// //     }
// //    }

// //    void remove(vector<int>& cnt,int number){

// //     for(int i=0;i<32;i++){
// //         if(!(number&1<<i)){
// //             cnt[i]--;
// //         }
// //     }
// //    }
// //     int longestSubsequence(vector<int>& nums) {
// //         int n=nums.size();
// //         int l=0;
// //         vector<int> cnt(32);
// //         int ans=0;

// //         for(int r=0;r<n;r++){
// //             int number=nums[r];
// //             // add functinon add cnnt of 0 for evrye digit
// //             add(cnt,number);
// //             // check zero gives tru e,,if all zero
// //             while(check_zero(cnt)){
// //                 remove(cnt,nums[l]);
// //                 l++;
// //             }
// //             ans=max(ans,r-l+1);

// //         }

// //         return ans;

//     }
// };
// // //     3    2  1    0
// //        0    1  0    1
// //        0    1  0    0
// //        0    1   1   1
class Solution {
public:
    int LIS(vector<int>& arr) {

        vector<int> tail;

        for (int num : arr) {

            auto it = lower_bound(tail.begin(), tail.end(), num);

            if (it == tail.end())
                tail.push_back(num);
            else
                *it = num;
        }

        return tail.size();
    }

    int longestSubsequence(vector<int>& nums) {

        int ans = 0;

        for (int bit = 0; bit < 31; bit++) {

            vector<int> filtered;

            // go bit by bit and check how many numbers which number have 1 in
            // that bit ,,then use lis
            for (int num : nums) {
                if (num & (1 << bit))
                    filtered.push_back(num);
            }

            ans = max(ans, LIS(filtered));
        }

        return ans;
    }
};
