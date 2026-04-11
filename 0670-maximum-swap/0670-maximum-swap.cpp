class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> last(10, -1);

        // Step 1: store last occurrence
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - '0'] = i;
        }

        // Step 2: try swapping
        for (int i = 0; i < s.size(); i++) {
            //99987 here 9 can not be swapped so check condinitiioon 9 to >s[i]-0 you should use    loop
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};