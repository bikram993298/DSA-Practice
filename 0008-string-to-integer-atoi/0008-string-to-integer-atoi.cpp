class Solution {
public:
    int myAtoi(string s) {

        int i = 0, n = s.size();

        //skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // check sign if  negatuve htn neigative if psitive nothing
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        //  convert digits
        long result = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

           

            result = result * 10 + digit;
            if(result*sign>=INT_MAX)return INT_MAX;
            if(result*sign<=INT_MIN) return INT_MIN;
            i++;
        }

        return sign * result;
    }
};