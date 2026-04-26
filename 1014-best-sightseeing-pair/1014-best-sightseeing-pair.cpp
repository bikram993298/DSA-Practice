class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();

        int best = values[0] + 0;
        // initllay 0the index
        int ans = 0;

        for (int j = 1; j < n; j++) {

            // use best previous i
            ans = max(ans, best + values[j] - j);

            // update best for future
            // fro evry j what are the bset i,smeans what are th best val[i]+i you got till index j ,,
            best = max(best, values[j] + j);
        }

        return ans;
    }
};