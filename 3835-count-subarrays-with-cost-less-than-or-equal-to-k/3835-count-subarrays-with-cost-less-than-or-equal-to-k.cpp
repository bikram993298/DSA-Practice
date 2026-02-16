// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, long long k) {
//        deque<int> maxi, mini;

//         int n=nums.size();
//         long long total=1LL*n*(n+1)/2;
//         // our idea is to calclute no of subtring that less than k




//         // the main idea is to count invalid because it clicks in my mind if i got valid subarray then right part of it like i to j is valid thn i to j+1,j+2 till n will be valid because i-j+1 will increase max may incarease but min will may be soame,,so monotinic increaseing so we are count subarray gretaer than k then minize it form totoal
//         // another in deque logic we top gives valid max or min,,so whenever get greter value for max que pop and push alogh with ,,if less eelmnt then push ,,play woth index not number,,
//         int l=0;
//         long long cnt=0;
//         for(int i=0;i<n;i++){
//           while(!maxi.empty() && nums[maxi.back()]<=nums[i]){
//             maxi.pop_back();
//           }
//           maxi.push_back(i);
//            while(!mini.empty() && nums[mini.back()]>=nums[i]){
//             mini.pop_back();
//           }
//           mini.push_back(i);


//           while(l<=i &&(long long)(i-l+1)*(nums[maxi.front()]-nums[mini.front()])>k){
//             cnt+=n-i;
//             // during shrinking phase it may happen in deques we have track elemnt so l index should be trackec maxi or mini front that in contrivutuin if it comes ir euqla to l that we are decrementing then pop,,it will give bext biggest elemnt,,in deque thus works
//             if(maxi.front() == l)
//                     maxi.pop_front();

//                 if(mini.front() == l)
//                     mini.pop_front();
//             l++;





            
//           }










//         }
//         return (total-cnt);
        
//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        deque<int> maxi, mini;

        int n = nums.size();

        long long ans = 0;

        int l = 0;

        for(int r = 0; r < n; r++) {

            while(!maxi.empty() && nums[maxi.back()] <= nums[r])
                maxi.pop_back();

            maxi.push_back(r);

            while(!mini.empty() && nums[mini.back()] >= nums[r])
                mini.pop_back();

            mini.push_back(r);

            while((long long)(nums[maxi.front()] - nums[mini.front()])
                  * (r - l + 1) > k) {

                if(maxi.front() == l)
                    maxi.pop_front();

                if(mini.front() == l)
                    mini.pop_front();

                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
