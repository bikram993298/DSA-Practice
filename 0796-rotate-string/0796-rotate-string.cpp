class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
// goal must be substring of s+s
        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
};