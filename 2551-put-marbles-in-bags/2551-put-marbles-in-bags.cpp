class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> costs;
        for (int i = 0; i < weights.size() - 1; i++) {
            costs.push_back(weights[i] + weights[i + 1]);
        }
        sort(costs.begin(), costs.end());
        
        long long maxScore = 0, minScore = 0;
        for (int i = 0; i < k - 1; i++) {
            minScore += costs[i];
            maxScore += costs[costs.size() - 1 - i];
        }
        return maxScore - minScore;
    }
};