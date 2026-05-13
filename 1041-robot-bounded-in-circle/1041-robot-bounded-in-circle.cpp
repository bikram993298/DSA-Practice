class Solution {
public:
    bool isRobotBounded(string instructions) {

        int x = 0, y = 0;

        char dir = 'N';
        // main logic you sre initially are towards N agagin after  total   loop if again N then never it will form loop ,it will go towarsd,

        for(char ch : instructions) {

            // Move forward
            if(ch == 'G') {

                if(dir == 'N') y++;
                else if(dir == 'S') y--;
                else if(dir == 'E') x++;
                else x--;

            }

            // Turn Left
            else if(ch == 'L') {

                if(dir == 'N') dir = 'W';
                else if(dir == 'W') dir = 'S';
                else if(dir == 'S') dir = 'E';
                else dir = 'N';

            }

            // Turn Right
            else {

                if(dir == 'N') dir = 'E';
                else if(dir == 'E') dir = 'S';
                else if(dir == 'S') dir = 'W';
                else dir = 'N';
            }
        }

        return (x == 0 && y == 0) || dir != 'N';
    }
};