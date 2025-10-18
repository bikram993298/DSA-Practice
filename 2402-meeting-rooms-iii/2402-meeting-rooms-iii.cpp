class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());
        
        // Count how many times each room is used
        vector<int> usedCount(n, 0);
        
        // Min-heap of {endTime, roomNumber} -> currently used rooms
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        
        // Min-heap of available room numbers
        priority_queue<int, vector<int>, greater<>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);
        
        for (auto& meet : meetings) {
            long long start = meet[0], end = meet[1];
            
            // Free up rooms that are done before this meeting starts
            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }
            
            // If a free room exists
            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busy.push({end, room});
                usedCount[room]++;
            } 
            else {
                // All rooms busy — extend the earliest one
                auto [freeTime, room] = busy.top();
                busy.pop();
                busy.push({freeTime + (end - start), room});
                usedCount[room]++;
            }
        }
        
        // Find room with max usage
        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (usedCount[i] > usedCount[maxRoom]) maxRoom = i;
        }
        return maxRoom;
    }
};
