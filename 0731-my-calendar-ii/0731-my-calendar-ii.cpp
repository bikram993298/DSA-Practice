class MyCalendarTwo {
public:
    map<int, int> events;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;

        int count = 0;

        for(auto &it : events) {
            count += it.second;

            if(count > 2) {
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }

        return true;
    }
};
