class Solution {
public:

    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        deque<pair<int,int>> dq;

        int ans = INT_MIN;

        for(auto &p : points) {

            int x = p[0];
            int y = p[1];

            // remove invalid points
            while(!dq.empty() &&
                  x - dq.front().second > k) {

                dq.pop_front();
            }

            // compute answer
            if(!dq.empty()) {

                ans = max(ans,
                          dq.front().first + x + y);
            }

            int val = y - x;

            // remove smaller useless values
            while(!dq.empty() &&
                  dq.back().first <= val) {

                dq.pop_back();
            }

            dq.push_back({val, x});
        }

        return ans;
    }
};