class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        // line sweep event array
        vector<int> event(n + 2, 0);

        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];

            // booking starts
            event[first] += seats;

            // booking ends after last
            event[last + 1] -= seats;
        }

        vector<int> ans(n);

        int currentSeats = 0;

        // sweep from left to right 0 bases flight
        for (int i = 1; i <= n; i++) {
            currentSeats += event[i];
            ans[i - 1] = currentSeats;
        }

        return ans;
    }
};