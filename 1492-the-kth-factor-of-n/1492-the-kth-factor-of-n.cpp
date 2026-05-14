class Solution {
public:
    int kthFactor(int n, int k) {
        
        vector<int> largeFactors;

        for(int i = 1; i * i <= n; i++) {

            if(n % i == 0) {

                k--;

                if(k == 0)
                    return i;

                // avoid duplicate for perfect square
                if(i != n / i)
                    largeFactors.push_back(n / i);
            }
        }

        // larger factors come in reverse order
        reverse(largeFactors.begin(), largeFactors.end());

        for(int x : largeFactors) {

            k--;

            if(k == 0)
                return x;
        }

        return -1;
    }
};