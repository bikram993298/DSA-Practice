class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        
        vector<int> ans(num_people, 0);

        int give = 1;   // next candies to give
        int i = 0;      // current person index

        while (candies > 0) {

            int currentGive = min(give, candies);

            ans[i % num_people] += currentGive;

            candies -= currentGive;

            give++;
            i++;
        }

        return ans;
    }
};