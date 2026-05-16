class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        int median = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(),
            [&](int a, int b) {

                int strengthA = abs(a - median);
                int strengthB = abs(b - median);

                // stronger first
                if (strengthA != strengthB)
                    return strengthA > strengthB;

                // if same strength -> larger number first
                return a > b;
            });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};