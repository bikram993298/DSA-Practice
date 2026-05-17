class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency
        for (int x : arr) {
            freq[x]++;
        }

        vector<int> v;

        // Store frequencies
        for (auto &it : freq) {
            v.push_back(it.second);
        }

        // Sort descending
        sort(v.begin(), v.end(), greater<int>());

        int removed = 0;
        int count = 0;
        int half = arr.size() / 2;

        for (int f : v) {
            removed += f;
            count++;

            if (removed >= half) {
                return count;
            }
        }

        return count;
    }
};