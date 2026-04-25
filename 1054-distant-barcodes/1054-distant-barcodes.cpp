class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        unordered_map<int, int> freq;

        // count frequency
        for (int x : barcodes) {
            freq[x]++;
        }

        // max heap -> {frequency, value}
        priority_queue<pair<int, int>> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        vector<int> ans;

        while (pq.size() >= 2) {

            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            int f1 = first.first;
            int v1 = first.second;

            int f2 = second.first;
            int v2 = second.second;

            ans.push_back(v1);
            ans.push_back(v2);

            f1--;
            f2--;

            if (f1 > 0) pq.push({f1, v1});
            if (f2 > 0) pq.push({f2, v2});
        }

        // if one element left
        if (!pq.empty()) {
            ans.push_back(pq.top().second);
        }

        return ans;
    }
};