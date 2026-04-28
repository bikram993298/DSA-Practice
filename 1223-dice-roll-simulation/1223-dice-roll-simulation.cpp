class Solution {
public:
    int mod = 1e9 + 7;
    
    // dp[pos][lastFace][count]
    // pos = current index
    // lastFace = previous dice face (0 to 5), 6 means no previous face
    // count = consecutive count of lastFace
    
    int dp[5001][7][16];

    int solve(int pos, int n, int lastFace, int count, vector<int>& rollMax) {
        // formed valid sequence of length n
        if (pos == n) return 1;

        if (dp[pos][lastFace][count] != -1)
            return dp[pos][lastFace][count];

        long long ans = 0;

        for (int face = 0; face < 6; face++) {
            
            // if same face as previous
            if (face == lastFace) {
                if (count < rollMax[face]) {
                    ans = (ans + solve(
                        pos + 1,
                        n,
                        face,
                        count + 1,
                        rollMax
                    )) % mod;
                }
            }
            else {
                // new face starts
                ans = (ans + solve(
                    pos + 1,
                    n,
                    face,
                    1,
                    rollMax
                )) % mod;
            }
        }

        return dp[pos][lastFace][count] = ans;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof(dp));

        // start with no previous face
        return solve(0, n, 6, 0, rollMax);
    }
};