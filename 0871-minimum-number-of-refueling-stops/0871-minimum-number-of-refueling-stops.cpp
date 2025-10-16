class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq; 
        int stops = 0, i = 0;
        long long fuel = startFuel;
        
        while (fuel < target) {
            while (i < stations.size() && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) return -1;
            fuel += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};
//story is if fuel is the ending point till i can go ,,if fule< target means you hsve to push all petrol pump within fuel end and use max heap most fuel top ,,then add in the fuel pop from heap check target is possible or not during pushing check if it in under the boundary ,,if some hoowyou have used all petrol pump till fuel end and till you not reached target then pq,empty so -1