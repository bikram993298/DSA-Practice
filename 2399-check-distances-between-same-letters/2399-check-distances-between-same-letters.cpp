class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> first(26, -1);
        
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            
            if(first[idx] == -1) {
                first[idx] = i;  // first occurrence
            } else {
                int dist = i - first[idx] - 1;
                
                if(dist != distance[idx]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};