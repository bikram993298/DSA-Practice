class Solution {
public:
    struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if (a.first == b.first)
                return a.second < b.second; // larger word should come first (worse)
            return  b.first<a.first;       // smaller freq is worse
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;

        for (auto w : words) {
            mp[w]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop(); // remove worst
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};


// | Approach        | Time       |
// | --------------- | ---------- |
// | Sorting         | O(n log n) |
// | Max heap        | O(n log n) |
// | Min heap (best) | O(n log k) |
