// class Solution {
// public:
//     vector<int> avoidFlood(vector<int>& rains) {
//         // i am thinking to use map,,if i get somenumber pluss1,
//         // gain that number then return empty
//         // if then get 0 mens i have count of dry palces ,,i will count_0++;
//         // thne if i face another rainy then check if count_0>0 thne 
        
//     }
// };
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();

        vector<int> ans(n, 1);

        unordered_map<int,int> lastRain;
      //  lake number  ->  last day it rained

        set<int> dryDays;
        //so the basic thing is you maintain a map where you will track which lake is forming which day rained,,then if you gaian get that day ,,search binary search on dry days indexes and find which day after last rain of that day is dry and remoe form dry and upadte last rained day 

        for(int i = 0; i < n; i++) {

            // rainy day
            if(rains[i] > 0) {

                int lake = rains[i];

                ans[i] = -1;

                // lake already full
                if(lastRain.count(lake)) {

                    // find dry day after previous rain
                    auto it = dryDays.upper_bound(lastRain[lake]);

                    // no dry day available
                    if(it == dryDays.end())
                        return {};

                    int dryDay = *it;

                    ans[dryDay] = lake;

                    dryDays.erase(it);
                }

                lastRain[lake] = i;
            }

            // dry day
            else {
                dryDays.insert(i);
            }
        }

        return ans;
    }
};