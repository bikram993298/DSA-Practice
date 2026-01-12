class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        std::sort(ages.begin(), ages.end());
        int n = ages.size();
        int totalRequests = 0;
        
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < n; ++i) {
            int x_age = ages[i];
            
            // Age too young to send any requests
            if (x_age < 15) continue;

            // Move 'left' to the first valid y: age[y] > 0.5 * x_age + 7
            while (left < n && ages[left] <= 0.5 * x_age + 7) {
                left++;
            }
            
            // Move 'right' to the last valid y: age[y] <= x_age
            // Note: Since the array is sorted, we include people with the same age
            while (right + 1 < n && ages[right + 1] <= x_age) {
                right++;
            }
            
            // The range [left, right] contains all valid y's for this x.
            // We subtract 1 because x cannot friend themselves.
            if (right >= left) {
                totalRequests += (right - left);
            }
        }
        
        return totalRequests;
    }
};


//age[y] <= 0.5 * age[x] + 7
//age[y] > age[x]
//age[y] > 100 && age[x] < 100 last ine is rebundant because of 2nd condition and
// if you want to intgreate 1st and 2nd condition then age[y]>=15