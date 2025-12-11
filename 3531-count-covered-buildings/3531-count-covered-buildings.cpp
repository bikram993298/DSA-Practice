class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int, int>> y(n+1, {INT_MAX, INT_MIN});
        vector<pair<int, int>> x(n+1, {INT_MAX, INT_MIN});
        int count = 0;
        
        for (auto it : buildings) {
            int f = it[0]; 
            int s = it[1]; 
            y[s].first = min(y[s].first, f);   
            y[s].second = max(y[s].second, f); 
            x[f].first = min(x[f].first, s);  
            x[f].second = max(x[f].second, s); 
        }
        
        for (auto it : buildings) {
            int f = it[0];
            int s = it[1];
            if (f > y[s].first && f < y[s].second && s > x[f].first && s < x[f].second) {
                count++;
            }
        }
        
        return count;
    }
};
