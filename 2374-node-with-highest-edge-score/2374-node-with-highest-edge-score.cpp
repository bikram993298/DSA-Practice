class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);

       
        for (int i = 0; i < n; i++) {
            score[edges[i]] += i;
        }

        // Find max score (tie → smallest index)
        long long maxScore = -1;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (score[i] > maxScore) {
                maxScore = score[i];
                ans = i;
            }
        }

        return ans;
    }
};
