class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> deg(n, 0);

        // Count degrees
        for (auto &r : roads) {
            deg[r[0]]++;
            deg[r[1]]++;
        }

        // Sort degrees
        sort(deg.begin(), deg.end());

        // Assign values 1..n
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += deg[i] * (i + 1);
        }

        return ans;
    }
};
