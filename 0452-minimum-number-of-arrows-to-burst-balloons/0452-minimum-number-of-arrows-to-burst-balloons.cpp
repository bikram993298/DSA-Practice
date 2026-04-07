//Sorting on the basis of "End coordinate"
// count how many non oerapiing area
//T.C : O(nlogn)
//S.C : O(1)

// main intituion i have arrows i ahd to minimize arrows to i have to maximimze the oevrpapiing so that by one arrow i can burts more bullon,os i have to sort by ending ,,lets think forst ending at 5,,no till 5 i hae to before 5 how many tsrating points that will be burst by me,,and start after 5 will not be burts by me so count++,,when there you merge intervel sort by starting point,,when maximimze overlaping sort by end interval
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });
        
        int count         = 1;
        int lastEndPoint  = points[0][1];
        
        for(int i = 1; i<n; i++) {
            int curr_startPoint = points[i][0];
            // I sort intervals by their end points because choosing the earliest ending balloon allows me to place the arrow optimally so that it can cover as many subsequent overlapping balloons as possible. This is a classic greedy strategy similar to interval scheduling, where picking the earliest finishing interval maximizes future choices.”
            if(curr_startPoint > lastEndPoint) {
                count++;
                lastEndPoint = points[i][1];
            }
        }
        
        return count;
    }
};