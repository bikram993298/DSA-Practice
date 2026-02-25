class Solution {
public:
    int maxDistinct(string s) {
        set<char>t;
        for(int i=0;i<s.size();i++)t.insert(s[i]);
        return t.size();
    }
};