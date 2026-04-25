class Solution {
public:
    int totalPeople;   // total number of people
    int half;          // people required in each city
    vector<vector<vector<int>>> dp;

    int solve(int i, int a, int b, vector<vector<int>>& costs) {

        // all people processed
        if (i == totalPeople) {
            if (a == half && b == half)
                return 0;

            return 1e9; // invalid case
        }

        if (dp[i][a][b] != -1)
            return dp[i][a][b];

        int sendA = 1e9;
        int sendB = 1e9;

        // send current person to city A
        if (a < half) {
            sendA = costs[i][0] + solve(i + 1, a + 1, b, costs);
        }

        // send current person to city B
        if (b < half) {
            sendB = costs[i][1] + solve(i + 1, a, b + 1, costs);
        }

        return dp[i][a][b] = min(sendA, sendB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {

        totalPeople = costs.size();   // full size
        half = totalPeople / 2;       // exactly half to each city

        dp.resize(totalPeople,
                  vector<vector<int>>(half + 1,
                  vector<int>(half + 1, -1)));

        return solve(0, 0, 0, costs);
    }
};