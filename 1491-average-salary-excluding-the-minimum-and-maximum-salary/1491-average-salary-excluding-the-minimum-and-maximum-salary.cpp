class Solution {
public:
    double average(vector<int>& salary) {
        
        int mini = INT_MAX;
        int maxi = INT_MIN;

        double sum = 0;

        for(int x : salary) {

            sum += x;

            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        return (sum - mini - maxi) / (salary.size() - 2);
    }
};