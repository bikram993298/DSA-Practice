class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        
        int count = 0;
        
        for(int x : deliciousness) {
            for(int p = 0; p <= 21; p++) {
                int target = (1 << p);
                int need = target - x;
                
                if(mp.count(need)) {
                    count = (count + mp[need]) % MOD;
                }
            }
            mp[x]++;
        }
        
        return count;
    }
};



// 🔍 Constraint Clarification

// You wrote:

// 0 <= deliciousness[i] <= 2^20

// (That “220v” is actually 2^20, not 220)

// 🧠 Step-by-Step Calculation
// 1️⃣ Max value
// max element = 2^20,,, we can choose only two elemnt so 2^20+2^20=2^21