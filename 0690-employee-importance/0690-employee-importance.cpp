// /*
// // Definition for Employee.
// class Employee {
// public:
//     int id;
//     int importance;
//     vector<int> subordinates;
// };
// */

// class Solution {
// public:

//     int solve(int id, vector<vector<int>>& adj, vector<int>& imp) {
//         int ans = imp[id];

//         for (auto it : adj[id]) {
//             ans += solve(it, adj, imp);
//         }

//         return ans;
//     }

//     int getImportance(vector<Employee*> employees, int id) {

//         vector<vector<int>> adj(2001);   // assuming id <= 2000
//         vector<int> imp(2001, 0);

//         for (auto it : employees) {
//             imp[it->id] = it->importance;

//             for (auto sub : it->subordinates) {
//                 adj[it->id].push_back(sub);
//             }
//         }

//         return solve(id, adj, imp);
//     }
// };

class Solution {
public:
    unordered_map<int, Employee*> mp;

    int dfs(int id) {
        Employee* emp = mp[id];

        int total = emp->importance;

        for (int sub : emp->subordinates) {
            total += dfs(sub);
        }

        return total;
    }

    int getImportance(vector<Employee*> employees, int id) {
        // map id → employee
        for (auto e : employees) {
            mp[e->id] = e;
        }

        return dfs(id);
    }
};