// class Solution {
// public:
//     int n;   // total number of people
//     vector<vector<vector<int>>> dp;

//     int solve(int i, int a, int b, vector<vector<int>>& costs) {

//         // all people processed
//         if (i == n) {
//             if (a == n / 2 && b == n / 2)
//                 return 0;

//             return 1e9; 
//         }

//         if (dp[i][a][b] != -1)
//             return dp[i][a][b];

//         int sendA = 1e9;
//         int sendB = 1e9;

       
//         if (a < n / 2) {
//             sendA = costs[i][0] + solve(i + 1, a + 1, b, costs);
//         }

     
//         if (b < n / 2) {
//             sendB = costs[i][1] + solve(i + 1, a, b + 1, costs);
//         }

//         return dp[i][a][b] = min(sendA, sendB);
//     }

//     int twoCitySchedCost(vector<vector<int>>& costs) {

//         n = costs.size(); // total people

//         dp.resize(n,
//                   vector<vector<int>>(n + 1,
//                   vector<int>(n + 1, -1)));

//         return solve(0, 0, 0, costs);
//     }
// };
// class Solution {
// public:
//     int n;   // total people / 2
//     vector<vector<int>> dp;

//     int solve(int i, int a, vector<vector<int>>& costs) {

//         // all people processed
//         if (i == costs.size()){
//             if (a == n / 2 && (i-a) == n / 2){
//                  return 0;

//             }
               

//              return 1e9; 
//        }
        
           

//         if (dp[i][a] != -1)
//             return dp[i][a];

//         int sendA = 1e9;
//         int sendB = 1e9;

//         // send to city A
//         if (a < n/2) {
//             sendA = costs[i][0] + solve(i + 1, a + 1, costs);
//         }

//         // people already sent to B = i - a
//         if ((i - a) < n/2) {
//             sendB = costs[i][1] + solve(i + 1, a, costs);
//         }

//         return dp[i][a] = min(sendA, sendB);
//     }

//     int twoCitySchedCost(vector<vector<int>>& costs) {

//         n = costs.size();

//         dp.resize(costs.size(), vector<int>(n + 1, -1));

//         return solve(0, 0, costs);
//     }
// };
//o(n^2)
//more optimal greedy
// Greedy Intuition

// Suppose initially:

// Send everyone to city A

// Then total cost:

// sum of all costA

// Now for some people we may switch them to city B.

// Question:

// Which people should go to B?

// Key Observation

// For each person compute:

// diff = costB - costA

// This tells:

// If diff is negative
// B is cheaper than A

// Very good candidate for city B.

// If diff is positive
// A is cheaper than B

// Better keep in city A.

// Greedy Rule

// Sort people by:

// (costB - costA)

// in increasing order.

// Then:

// first n people → city B
// remaining n people → city A

// This guarantees minimum answer.
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        sort(costs.begin(), costs.end(),
            [](vector<int>& a, vector<int>& b) {
                return (a[0] - a[1]) > (b[0] - b[1]);
            });

        int n = costs.size() / 2;
        int ans = 0;

        // first n -> city B
        for (int i = 0; i < n; i++) {
            ans += costs[i][1];
        }
//         (A - B) desccending
// → first n to A,,,beacuse a jtot besi positie tot besi ,,b is cheaper
// → rest to B

        // remaining n -> city A
        for (int i = n; i < 2 * n; i++) {
            ans += costs[i][0];
        }

        return ans;
    }
};