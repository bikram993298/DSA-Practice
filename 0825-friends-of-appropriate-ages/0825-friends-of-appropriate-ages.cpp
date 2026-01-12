class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int totalRequests = 0;

        for (int i = 0; i < ages.size(); ++i) {
            int x_age = ages[i];
            if (x_age < 15) continue; // Rule 1 makes requests impossible below age 15

            // Find first y where age[y] > 0.5 * x_age + 7
            // upper_bound finds the first element > value
            auto it_low = upper_bound(ages.begin(), ages.end(), 0.5 * x_age + 7);
            int left = distance(ages.begin(), it_low);

            // Find first y where age[y] > x_age
            auto it_high = upper_bound(ages.begin(), ages.end(), x_age);
            int right =distance(ages.begin(), it_high) - 1;
            //distance gives 0 based index form iterator

            // if (right >= left) {
                totalRequests += (right - left);
            // }
        }
        return totalRequests;
    }
};
//age[y] <= 0.5 * age[x] + 7
//age[y] > age[x]
//age[y] > 100 && age[x] < 100 last ine is rebundant because of 2nd condition and
// if you want to intgreate 1st and 2nd condition then age[y]>=15