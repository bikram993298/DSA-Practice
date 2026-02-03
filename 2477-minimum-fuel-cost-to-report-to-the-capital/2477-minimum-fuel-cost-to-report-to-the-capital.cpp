class Solution {
public:
    long long fuel = 0;
    int seats;
    vector<vector<int>> adj;

    long long dfs(int node, int parent) {
        long long people=1;

        for (int nei:adj[node]) {
            if (nei==parent) continue;
            people +=dfs(nei, node);
        }
//in yhis question we have in every recurseion we have to plus people contribution t o fuel and that people to parent which to give parent that we have to return and every dfs what to add fuel add
        // except capital, everyone moves to parent
        if (node != 0) {
            // fuel += (people + seats - 1) / seats; // ceil division
             fuel += (long long)ceil((double)people / seats);
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats_) {
        seats = seats_;
        int n = roads.size() + 1;
        adj.resize(n);

        for (auto &r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }

        dfs(0, -1);
        return fuel;
    }
};
