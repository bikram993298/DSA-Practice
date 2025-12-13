// class Solution {
// public:
//     int n;
//     vector<int> arr1, arr2;

//     long long solve(int i, int prev) {
//         if (i == n) return 0;

//         long long ans = 1e9;


//         // try keeping arr1[i]
//         if (arr1[i] > prev) {
//             ans = solve(i + 1, arr1[i]);
//         }

//         int m = arr2.size();

//         // try replacing with every arr2[j]
//         for (int j = 0; j < m; j++) {
//             if (arr2[j] > prev) {
//                 long long temp = solve(i + 1, arr2[j]);
//                // here facing problem beacuse we have to take minimum moves you declared ans as intmax,,so when there is valid case ans will be min ans and solve next recursion +1,, if somegow it gives int_max then int will be over flow so take long long or another if(sove giving intmax ) then   if (temp != INF) {
//                 //     ans = min(ans, 1 + temp);
//                 // } 
//                     ans = min(ans, 1 + temp);
                
//             }
//         }

//         return ans;
//     }

//     int makeArrayIncreasing(vector<int>& a1, vector<int>& a2) {
//         arr1 = a1;
//         arr2 = a2;
//         n = arr1.size();

//         int res = solve(0, -1);
//         return res>= 1e9 ? -1 : res;
//     }
// };
// but this will not work of because 2 states and one loop n3 complexcity so think another
class Solution {
public:
    const int INF = 1e9;
    int n;
    vector<int> arr1, arr2;
    map<pair<int,int>, int> dp;

    int solve(int i, int prev) {
        if (i == n) return 0;

        if (dp.count({i, prev}))
            return dp[{i, prev}];

        int ans = INF;

        // keep
        if (arr1[i] > prev) {
            ans = solve(i + 1, arr1[i]);
        }

        // replace (ONLY ONE choice)
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            ans = min(ans, 1 + solve(i + 1, *it));
        }

        return dp[{i, prev}] = ans;
    }

    int makeArrayIncreasing(vector<int>& a1, vector<int>& a2) {
        arr1 = a1;
        arr2 = a2;
        n = arr1.size();

        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int res = solve(0, -1);
        return res >= INF ? -1 : res;
    }
};
