class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0, j = 0;
        int n = start.size();
        // main learning is the x are the spces and L will go left and right will go right afyer each move,,realtive ordering of L and R will be same ,,so main false case,,if  i finihsed an s j not finised and vice cresa then false

        while(i < n || j < n) {
// find first 
//L or R           
 while(i < n && start[i] == 'X') i++;
            while(j < n && result[j] == 'X') j++;

            // both finished
            if(i == n && j == n) return true;

            // one finished, other not
            if(i == n || j == n) return false;

            // characters must match because if first not X is not matched that means ha relativeordceing galat
            // at evry no x they s hould be equal
            if(start[i] != result[j]) return false;

            // movement constraints
            // start ka L agar choota he atrget se fals because L to right move nehi kar skta
            if(start[i] == 'L' && i < j) return false;
            if(start[i] == 'R' && i > j) return false;

            i++;
            j++;
        }

        return true;
    }
};