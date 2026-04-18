class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int,int>> events;

        //  Convert buildings into events
        for (auto &b : buildings) {
            events.push_back({b[0], -b[2]});
             // start event giving heights idont know the excat erason may be t idcate it is the straing of that
            events.push_back({b[1], b[2]});  // end event
        }

        // Step 2: Sort events
        sort(events.begin(), events.end());
// based on the staring we sort the then wee need cuurent max,if xurrent max ischangin g then we will sotre it and current_max pdate,,if not then if we got end o fht ebuilding then we will erase that building height,,if cuurent max is changing then store if not then no change
        // Step 3: Multiset to maintain active heights
        multiset<int> heights;
        heights.insert(0); // ground level

        vector<vector<int>> result;
        int prevMax = 0;

        // Step 4: Process events
        for (auto &e : events) {
            int x = e.first;
            int h = e.second;

            if (h < 0) {
                // we hae to tarack staring index so that heigh<0 we oush and see any hegiht chneg 
                // always start- because you ar estoring in -
                // start of building
                heights.insert(-h);
            } else {
                // end of building
                heights.erase(heights.find(h));
            }

            // Step 5: Current max height
            int currMax = *heights.rbegin();

            // Step 6: If skyline changes, record it
            if (currMax != prevMax) {
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }

        return result;
    }
};