class Solution {
public:
    int brokenCalc(int start, int target) {
        int steps = 0;

        // your required code start from here

        while (target > start) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
            steps++;
        }

        // if target <= start → only subtract
        steps += (start - target);

        // your required code end here

        return steps;
    }
};