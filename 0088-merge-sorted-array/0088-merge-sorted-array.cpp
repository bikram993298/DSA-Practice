class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j])
                temp.push_back(nums1[i++]);
            else
                temp.push_back(nums2[j++]);
        }
        
        while(i < m) temp.push_back(nums1[i++]);
        while(j < n) temp.push_back(nums2[j++]);
        
        for(int k = 0; k < m + n; k++)
            nums1[k] = temp[k];
    }
};


// class Solution {
//   //  tc:o(n+m) sc o(n+m) with array containg duplicates eelemnts
// //     vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// //     int l1 = 0, l2 = 0;
// //     vector<int> ans;

// //     while (l1 < nums1.size() && l2 < nums2.size()) {
// //         if (nums1[l1] < nums2[l2]) {
// //             if (ans.empty() || ans.back() != nums1[l1])
// //                 ans.push_back(nums1[l1]);
// //             l1++;
// //         } else if (nums1[l1] > nums2[l2]) {
// //             if (ans.empty() || ans.back() != nums2[l2])
// //                 ans.push_back(nums2[l2]);
// //             l2++;
// //         } else {
// //             if (ans.empty() || ans.back() != nums1[l1])
// //                 ans.push_back(nums1[l1]);
// //             l1++;
// //             l2++;
// //         }
// //     }

// //     // Add remaining elements from nums1
// //     while (l1 < nums1.size()) {
// //         if (ans.empty() || ans.back() != nums1[l1])
// //             ans.push_back(nums1[l1]);
// //         l1++;
// //     }

// //     // Add remaining elements from nums2
// //     while (l2 < nums2.size()) {
// //         if (ans.empty() || ans.back() != nums2[l2])
// //             ans.push_back(nums2[l2]);
// //         l2++;
// //     }

// //     return ans;
// // }

// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
//      int l1=m-1;
//      int l2=n-1;
//      int k=m+n-1;
//      while(l1>=0 && l2>=0){
//         if(nums1[l1]>nums2[l2]){
//             nums1[k]=nums1[l1];
//             k--;
//             l1--;
//         }else if(nums2[l2]>nums1[l1]){
//             nums1[k]=nums2[l2];
//             k--;
//             l2--;
//         }else{
//             nums1[k--]=nums2[l2--];
//         }
//      }
//      while(l2>=0){
//         nums1[k--]=nums2[l2--];
//      }
//      return;
//     }
// };