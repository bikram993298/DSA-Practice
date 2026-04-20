class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> res;

        // your required code start from here

        for (int i = n - 1; i >= 0; i--) {
            int sum = num[i] + k;

            res.push_back(sum % 10);  // store last digit
            k = sum / 10;             // carry forward
        }

        // if still carry left
        while (k > 0) {
            res.push_back(k % 10);
            k /= 10;
        }

        // reverse result
        reverse(res.begin(), res.end());

        // your required code end here

        return res;
    }
};