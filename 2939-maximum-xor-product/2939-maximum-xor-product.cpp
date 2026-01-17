class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const long long MOD = 1e9 + 7;

        long long A = a, B = b;

        //so basicaally we have to move from msb to lsb because most significant figure  gives more value to lsb
        // intially all the bits are zero so if you want to shift 1 then only make operation//A will tract the product of a*x ,,,
    

     

        for(int i = n - 1; i >= 0; i--) {
            long long bit = 1LL << i;
            int ba = (A & bit) ? 1 : 0;
            int bb = (B & bit) ? 1 : 0;

            if(ba == bb) {
                // both 0 -> flip to make both 1
                if(ba == 0) {
                    A ^= bit;
                    B ^= bit;
                }
                // both 1 -> do nothing
            } 
            else {
                // bits different: decide based on balancing
                if(A < B) {
                    // make A's bit = 1
                    if(ba == 0) {
                        A ^= bit;
                        B ^= bit;
                    }
                } else {
                    // make B's bit = 1
                    if(bb == 0) {
                        A ^= bit;
                        B ^= bit;
                    }
                }
            }
        }

        return ( (A % MOD) * (B % MOD) ) % MOD;
    }
};
