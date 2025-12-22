class Solution {
public:
    unordered_map<string, long long> dp;
    int K;

    long long solve(long long pos, int jump, bool canDown) {

        // pruning because ther eis only one option to down
        if (pos > K + 1) return 0;

      
        string key = to_string(pos) + "#" + to_string(jump) + "#" + to_string(canDown);
        if (dp.count(key)) return dp[key];

        long long ways = 0;

        // reaching k counts as a valid way
        if (pos == K) ways++;

        if (canDown && pos > 0) {
            ways += solve(pos - 1, jump, false);
        }

        
        long long nextPos = pos + (1LL << jump);
        ways += solve(nextPos, jump + 1, true);

        return dp[key] = ways;
    }

    int waysToReachStair(int k) {
        K = k;
        return solve(1, 0, true);
    }
};
// 3️⃣ Most states are NEVER visited ❌

// Even though:

// pos ranges up to k+1

// jump up to ~30

// 👉 Only a tiny fraction of these combinations are actually reachable
