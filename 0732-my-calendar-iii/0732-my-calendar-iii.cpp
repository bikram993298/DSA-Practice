class MyCalendarThree {
public:
    map<int,int> timeline;

    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;

        int curr = 0, maxOverlap = 0;

        for (auto &p : timeline) {
            curr += p.second;
            maxOverlap = max(maxOverlap, curr);
        }

        return maxOverlap;
    }
};