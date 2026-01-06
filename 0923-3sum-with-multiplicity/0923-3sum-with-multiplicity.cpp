class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int T = target - arr[i];
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = arr[j] + arr[k];

                if (sum < T) {
                    j++;
                } 
                else if (sum > T) {
                    k--;
                } 
                else {
                    if (arr[j] != arr[k]) {
                        long long leftCount = 1, rightCount = 1;

                        while (j + 1 < k && arr[j] == arr[j + 1]) {
                            leftCount++;
                            j++;
                        }
                        while (k - 1 > j && arr[k] == arr[k - 1]) {
                            rightCount++;
                            k--;
                        }

                        ans = (ans + leftCount * rightCount) % MOD;
                        j++;
                        k--;
                    } 
                    else {
                        long long len = k - j + 1;
                        ans = (ans + (len * (len - 1)) / 2) % MOD;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};  