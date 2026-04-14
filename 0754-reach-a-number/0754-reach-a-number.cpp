class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);  // symmetry
        
        int sum = 0, k = 0;
        // it is always 1+2+3+4+5+6 like this
        // and sum<target increase k,sum k,,if sum-target is eevn then only you can mkake target so that will be ans
        // sum 21 target 11,,,,sum-target 10,,so it is even because 2* any number will be ven if we minise 5 it will be give target but noomber of steps will be same
        
        while (sum < target || (sum - target) % 2 != 0) {
            k++;
            sum += k;
        }
        
        return k;
    }
};