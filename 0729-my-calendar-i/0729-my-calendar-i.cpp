class MyCalendar {
public:
    vector<pair<int,int>> bookings;

    MyCalendar() {}

    bool book(int start, int end) {
        for (auto &p : bookings) {
            if (start < p.second && end > p.first) {
                return false; // overlap
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};