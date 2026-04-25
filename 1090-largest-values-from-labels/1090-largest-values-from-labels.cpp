// // class Solution {
// // public:
// //     int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
// //         // 5 4  // 3  2 /// 1
// //         // 5 // 4 3 2// 1
// //         // 9 8 8 // 7 6
// //         // we have to make coonected comonent then take highest from each components,removve ten agian if same componet check uselimit ,,thus we hae to select unwanted items
        
// //     }
// // };

// class Solution {
// public:
//     int largestValsFromLabels(vector<int>& values,
//                               vector<int>& labels,
//                               int numWanted,
//                               int useLimit) {
        
//         int n = values.size();

//         vector<pair<int, int>> arr;

//         // store {value, label}
//         for (int i = 0; i < n; i++) {
//             arr.push_back({values[i], labels[i]});
//         }

//         // sort in descending order of value
//         sort(arr.begin(), arr.end(), greater<pair<int, int>>());

//         unordered_map<int, int> used;

//         int ans = 0;
//         int taken = 0;

//         for (int i = 0; i < n; i++) {
//             int value = arr[i].first;
//             int label = arr[i].second;

//             // skip if this label already reached limit
//             if (used[label] == useLimit) {
//                 continue;
//             }

//             ans += value;
//             used[label]++;
//             taken++;

//             // enough elements selected
//             if (taken == numWanted) {
//                 break;
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int largestValsFromLabels(vector<int>& values,
                              vector<int>& labels,
                              int numWanted,
                              int useLimit) {
        
        int n = values.size();

        // group values by same label (like connected component idea)
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[labels[i]].push_back(values[i]);
        }

        vector<int> candidates;

        // from each component(label),
        // take at most useLimit highest values
        for (auto &it : mp) {
            vector<int>& temp = it.second;

            sort(temp.begin(), temp.end(), greater<int>());

            for (int i = 0; i < temp.size() && i < useLimit; i++) {
                candidates.push_back(temp[i]);
            }
        }

        // now from all selected useful values,
        // take top numWanted values
        sort(candidates.begin(), candidates.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < candidates.size() && i < numWanted; i++) {
            ans += candidates[i];
        }

        return ans;
    }
};