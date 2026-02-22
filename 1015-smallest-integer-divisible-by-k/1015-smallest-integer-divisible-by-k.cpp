class Solution {
public:
    int smallestRepunitDivByK(int k) {
         int num = 0;
        // if u are thinking to make numer one by one till k then you can store it in long long int because  2 <= k <= 105 ,,only if k is 9 means upto value,,10^9 we can store,,means 9 digit not 10^5 digits
        for(int len = 1; len <= k; len++) {
            // so we are using modulo proprery
            
            num= (num * 10 + 1) % k;
            
            if(num == 0)
                return len;
        }
        
        return -1;
        
    }
};