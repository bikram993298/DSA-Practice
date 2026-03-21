// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.size();
//         int m = needle.size();

//         // if (m == 0) return 0;

//         for (int i = 0; i <= n - m; i++) {
//             int j = 0;
//             // brute froce is for evry index i while loopp try to check if by making equal gin g you are reaching m sizeor not
//             while (j < m && haystack[i + j] == needle[j]) {
//                 j++;
//             }
//             if (j == m) return i;
//         }
//         return -1;
//     }
// };

// Time: O(n * m)
// Space: O(1)
//KMP – Interview Ready

class Solution {
public:
    int strStr(string h, string n) {
        int m = n.size(), n1 = h.size();
        vector<int> lps(m, 0);

        for(int i = 1, len = 0; i < m; ){
            if(n[i] == n[len]) lps[i++] = ++len;
            else if(len) len = lps[len-1];
            else i++;
        }

        for(int i = 0, j = 0; i < n1; ){
            if(h[i] == n[j]){
                i++; j++;
                if(j == m) return i - j;
            }
            else if(j) j = lps[j-1];
            else i++;
        }
        return -1;
    }
};