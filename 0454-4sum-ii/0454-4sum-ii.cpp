class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, 
                     vector<int>& C, vector<int>& D) {
        
        unordered_map<int, int> mp;

        // Step 1: Store A + B sums
        for(int a : A) {
            for(int b : B) {
                mp[a + b]++;
            }
        }

        int count = 0;

        // Step 2: Match with C + D
        for(int c : C) {
            for(int d : D) {
                int target = -(c + d);

                if(mp.find(target) != mp.end()) {
                    count += mp[target];
                }
            }
        }

        return count;
    }
};