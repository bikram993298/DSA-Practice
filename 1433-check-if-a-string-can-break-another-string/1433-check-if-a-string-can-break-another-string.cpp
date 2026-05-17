class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool first = true;
        bool second = true;

        for (int i = 0; i < s1.size(); i++) {

            if (s1[i] < s2[i])
                first = false;

            if (s2[i] < s1[i])
                second = false;
        }

        return first || second;
    }
};