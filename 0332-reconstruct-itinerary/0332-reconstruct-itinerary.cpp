class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> ans;

    void dfs(string node) {
        auto &pq = mp[node];

        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next);
        }

        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &t : tickets) {
            mp[t[0]].push(t[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// tickets = [
//  ["JFK","KUL"],
//  ["JFK","NRT"],
//  ["NRT","JFK"]
// ]


// dfs("JFK")
//  ├── pop "KUL"
//  │    dfs("KUL")
//  │     └── no edges
//  │     └── ans.push("KUL")
//  ├── pop "NRT"
//  │    dfs("NRT")
//  │     ├── pop "JFK"
//  │     │    dfs("JFK")
//  │     │     └── no edges
//  │     │     └── ans.push("JFK")
//  │     └── ans.push("NRT")
//  └── ans.push("JFK")


// ["KUL", "JFK", "NRT", "JFK"]
// Final Answer (after reverse)
// ["JFK", "NRT", "JFK", "KUL"]
