#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        int n = details.size();
        DSU ds(n);
        unordered_map<string, int> mapMailNode;

        // Step 1: Map emails to account index and union
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i; // first time seeing this mail
                } else {
                    ds.unite(i, mapMailNode[mail]); // merge accounts
                }
            }
        }

        // Step 2: Group all emails by their parent DSU node
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.find(it.second);
            mergedMail[node].push_back(mail);
        }

        // Step 3: Prepare final answer
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]); // name
            for (auto &mail : mergedMail[i])
                temp.push_back(mail);
            ans.push_back(temp);
        }

        return ans;
    }
};
