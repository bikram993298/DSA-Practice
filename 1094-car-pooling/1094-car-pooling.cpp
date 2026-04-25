class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int maxDistance = 0;

        // find maximum drop location
        for (int i = 0; i < trips.size(); i++) {
            maxDistance = max(maxDistance, trips[i][2]);
        }

        // sweep line / event array
        vector<int> event(maxDistance + 1, 0);

        for (int i = 0; i < trips.size(); i++) {
            int passengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            // pickup
            event[from] += passengers;

            // drop
            event[to] -= passengers;
        }

        int currentPassengers = 0;

        // prefix sum over event array
        for (int i = 0; i <= maxDistance; i++) {
            currentPassengers += event[i];

            if (currentPassengers > capacity) {
                return false;
            }
        }

        return true;
    }
};