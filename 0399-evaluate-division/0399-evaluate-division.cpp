#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& vis) {
        if (!graph.count(src) || !graph.count(dest)) return -1.0;
        if (src == dest) return 1.0;
        vis.insert(src);

        for (auto& [nbr, val] : graph[src]) {
            if (vis.count(nbr)) continue;
            double res = dfs(nbr, dest, graph, vis);
            if (res != -1.0)
                return res * val; // multiply current edge
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build graph
        for (int i = 0; i < equations.size(); ++i) {
            auto& a = equations[i][0];
            auto& b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;
        for (auto& q : queries) {
            unordered_set<string> vis;
            ans.push_back(dfs(q[0], q[1], graph, vis));
        }
        return ans;
    }
};
