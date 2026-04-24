class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        sort(clips.begin(), clips.end());

        int n = clips.size();
        int i = 0;

        int ans = 0;
        int currentEnd = 0;
        int farthest = 0;

        while (currentEnd < time) {

            // check all clips starting before or at currentEnd
            while (i < n && clips[i][0] <= currentEnd) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            // cannot move further
            if (farthest == currentEnd)
                return -1;

            ans++;
            currentEnd = farthest;
        }

        return ans;
    }
};