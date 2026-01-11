class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());

      
        int maxMoves = max(
            stones[n - 1] - stones[1]+1 - (n - 1),
            stones[n - 2] - stones[0]+1 - (n - 1)
        );

       
        int minMoves = n;
        int i = 0;

        for (int j = 0; j < n; j++) {
            while (stones[j] - stones[i] + 1 > n) {
                i++;
            }

            int windowSize = j - i + 1;

          
            if (windowSize == n - 1 &&
                stones[j] - stones[i] + 1 == n - 1) {
                minMoves = min(minMoves, 2);
            } else {
                minMoves = min(minMoves, n - windowSize);
            }
        }

        return {minMoves, maxMoves};
    }
};
