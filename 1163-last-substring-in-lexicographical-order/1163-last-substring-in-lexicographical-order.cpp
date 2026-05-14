class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, k = 0;
// main idea is here we have to compare substring from i and j becuse if we consider prefix starting form j it wil definately subtring will have bigger so compare only subctring by twwo pointer now i will be 0 then jwill be i+1 ,,maintain this if somehow aab
//aac c is dieffernt so aab's a,b will neveer createt any suffix that will be bigger than substring starting aac,,because c can be more than them all substrings,,we can skip i+k now 
        while (j + k < s.size()) {
            if (s[i + k] == s[j + k]) {
                k++;
            }
            else if (s[i + k] > s[j + k]) {
                j = j + k + 1;
                k = 0;
            }
            else {
               
                i=max(j,i+k+1);
               j=i+1;
                k = 0;
            }
        }

        return s.substr(i);
    }
};
//i have dount