class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> p(n);

        for (int i = 0; i < n; i++) {
            p[i] = {costs[i], capacity[i]};
        }

        // sort by cost
        sort(p.begin(), p.end());

        // prefix max of capacity
        vector<int> pre(n);
        pre[0] = p[0].second;
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], p[i].second);
        }

        int ans = 0;

        // single machine case
        for (int i = 0; i < n; i++) {
            if (p[i].first < budget)
                ans = max(ans, p[i].second);
        }

        // two machines
        for (int i = 1; i < n; i++) {
            int remaining = budget - p[i].first - 1;
            if (remaining < 0) continue;

            int l = 0, r = i - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (p[mid].first <= remaining) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, p[i].second + pre[idx]);
            }
        }

        return ans;
    }
};
