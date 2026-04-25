// class Solution {
// public:
//     int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
//         // 5 4  // 3  2 /// 1
//         // 5 // 4 3 2// 1
//         // 9 8 8 // 7 6
//         // we have to make coonected comonent then take highest from each components,removve ten agian if same componet check uselimit ,,thus we hae to select unwanted items
        
//     }
// };

class Solution {
public:
    int largestValsFromLabels(vector<int>& values,
                              vector<int>& labels,
                              int numWanted,
                              int useLimit) {
        
        int n = values.size();

        vector<pair<int, int>> arr;

        // store {value, label}
        for (int i = 0; i < n; i++) {
            arr.push_back({values[i], labels[i]});
        }

        // sort in descending order of value
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        unordered_map<int, int> used;

        int ans = 0;
        int taken = 0;

        for (int i = 0; i < n; i++) {
            int value = arr[i].first;
            int label = arr[i].second;

            // skip if this label already reached limit
            if (used[label] == useLimit) {
                continue;
            }

            ans += value;
            used[label]++;
            taken++;

            // enough elements selected
            if (taken == numWanted) {
                break;
            }
        }

        return ans;
    }
};