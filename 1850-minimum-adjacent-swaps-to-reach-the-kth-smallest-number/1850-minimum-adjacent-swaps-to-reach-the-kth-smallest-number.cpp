class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;

      
        while (k--) {
            next_permutation(target.begin(), target.end());
        }

        int swaps = 0;
        int n = num.size();

        for (int i = 0; i < n; i++) {
            if (num[i] == target[i]) continue;

            int j = i;
            while (num[j] != target[i]) j++;

            ///  1 1 1 1 2
            //k =2
            // kth pemaution will be target= 2 1 1 1 1
            //first see msmstach 0th indexj=i;;find in nums wherer it matches with atrget ith index 4ht index now while(j>i beacuse i have to make equal ith index of all nums and target so ) make swap adjacent and j--

            // bring num[j] to position i
            while (j > i) {
                swap(num[j], num[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};
