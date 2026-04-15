
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        // important greedy problem beaucces in eery index we are finding thath first ka maximum should be greater than second aort ka minum if yes then chunk can be made then go ,,if it is i 0 the inex edge  case because 0 th index -1 will minimummm then last iedx suffix mean will be there
        vector<int> prefixMax(begin(arr), end(arr));
        vector<int> suffixMin(begin(arr), end(arr));

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunksCount = 1;
        for (int i = 1; i < n; i++) {
            int pehleKaMax =  prefixMax[i - 1] ;
            int baadKaMin  = suffixMin[i];
            
            if(pehleKaMax < baadKaMin) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};

//T.C : O(n)
//S.C : O(n)