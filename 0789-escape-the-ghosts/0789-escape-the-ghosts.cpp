class Solution {
public:
    int dist(pair<int,int> a, pair<int,int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        pair<int,int> start = {0,0};
        pair<int,int> tar = {target[0], target[1]};

        int myDist = dist(start, tar);

        for(auto &g : ghosts) {
            pair<int,int> ghost = {g[0], g[1]};
            int ghostDist = dist(ghost, tar);

            if(ghostDist <= myDist) {
                return false;
            }
        }

        return true;
    }
};