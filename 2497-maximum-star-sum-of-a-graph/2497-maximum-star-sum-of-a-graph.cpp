class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);

       
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MIN;

        for (int u = 0; u < n; u++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            // to make top k higest use for loop then if size graeter then then pop

            // collect top k positive neighbors
            for (int v : adj[u]) {
                if (vals[v] > 0) {
                    pq.push(vals[v]);
                    if ((int)pq.size() > k) {
                        pq.pop(); // remove smallest
                    }
                }
            }

            int sum = vals[u];
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
// Complexity

// Each edge processed twice

// Heap operations: O(log k)

// Total: O(E log k)
// ➡️ Faster than sorting when k is small
