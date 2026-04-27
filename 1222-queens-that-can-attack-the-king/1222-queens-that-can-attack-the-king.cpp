class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int,int>> st;

        for (auto &q : queens) {
            st.insert({q[0], q[1]});
        }
        // npto cheking from evry quesen because thus you will not got if there is anyother queen then it will be blcoekd,,so insetead start from king and four direction jetet thako jabtak any hit in queen ,,aa smuch u got hit break

        vector<vector<int>> ans;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1},
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        int x = king[0];
        int y = king[1];

        for (auto &d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;

            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (st.count({nx, ny})) {
                    ans.push_back({nx, ny});
                    break;
                }

                nx += d.first;
                ny += d.second;
            }
        }

        return ans;
    }
};