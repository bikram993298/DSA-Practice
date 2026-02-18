class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers,
                          vector<int>& center,
                          int radius) {

        // max heap based on quality,
        // if tie → smaller x, then smaller y
        priority_queue<
            pair<int, pair<int,int>>
        > pq;

        for(int i = 0; i < towers.size(); i++) {

            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];

            int dist = abs(x - center[0]) +
                       abs(y - center[1]);

            if(dist <= radius) {

                // push quality,
                // and negative coordinates for lexicographic min
                // max heap max quality but coordinate nedd reverse min or create custom operator or use minize
                pq.push({q, {-x, -y}});
            }
        }

        if(pq.empty())
            return {-1, -1};

        auto top = pq.top();

        return {-top.second.first,
                -top.second.second};
    }
};
