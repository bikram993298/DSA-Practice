class Solution {
public:

    const int MOD = 1e9 + 7;

    vector<int> hatToPeople[41];
    // in bitmask how define state alue 2^n n mask size

    int dp[41][1 << 10];

    int n;

    int solve(int hat, int mask) {
        // in teh recusion what are doing going to each hat and goin to adjancy which perfson like choseone check if previously got if not gone then hat+1,and recursion
        // or NOTHER CHOICE CAN BE SKIP Tthe hat then hat+1,not  chnage in mask
        //

        // everyone assigned
        if (mask == (1 << n) - 1)
            return 1;

        // no hats left
        if (hat > 40)
            return 0;

        if (dp[hat][mask] != -1)
            return dp[hat][mask];

        long long ways = 0;

        // skip current hat
        ways = solve(hat + 1, mask);

        // assign current hat
        for (int person : hatToPeople[hat]) {

            // person already assigned
            if (mask & (1 << person))
                continue;

            ways += solve(
                hat + 1,
                mask | (1 << person)
            );

            ways %= MOD;
        }

        return dp[hat][mask] = ways;
    }

    int numberWays(vector<vector<int>>& hats) {

        n = hats.size();

        // build hat -> people map,,fro each hat where i can go person
        for (int person = 0; person < n; person++) {

            for (int hat : hats[person]) {

                hatToPeople[hat].push_back(person);
            }
        }
        // HERE N IS 10,,BRUTE FROCE IS THERE IS HATS 40,,SO 2^40 IF U THINK frist hat will given to which person,second whic then (n)^40,,no n is small so you can make mask of people,,mask will define n=10 ,means which people get hats

        memset(dp, -1, sizeof(dp));

        return solve(1, 0);
    }
};