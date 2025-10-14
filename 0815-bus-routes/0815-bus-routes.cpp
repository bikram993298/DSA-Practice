class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        unordered_map<int, vector<int>> stopToBus;
        for (int bus = 0; bus < routes.size(); bus++) {
            for (int stop : routes[bus]) {
                stopToBus[stop].push_back(bus);
            }
        }
        
        queue<pair<int,int>> q; // bus, buses_taken
        vector<bool> visitedBus(routes.size(), false);
        unordered_set<int> visitedStop;
        
        for (int bus : stopToBus[source]) {
            q.push({bus, 1});
            visitedBus[bus] = true;
        }
        
        while (!q.empty()) {
            auto [bus, busesTaken] = q.front(); q.pop();
            for (int stop : routes[bus]) {
                if (stop == target) return busesTaken;
                if (visitedStop.count(stop)) continue;
                visitedStop.insert(stop);
                for (int nextBus : stopToBus[stop]) {
                    if (!visitedBus[nextBus]) {
                        visitedBus[nextBus] = true;
                        q.push({nextBus, busesTaken + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};