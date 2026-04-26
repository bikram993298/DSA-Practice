class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) {
            return;
        }

        // smaller one becomes parent
//         Because during union, we always force:

// smaller character = parent

// This is the whole reason.
        if (pa < pb) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        parent.resize(26);

        // initialize DSU
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // build equivalence groups
        for (int i = 0; i < s1.size(); i++) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';

            unite(a, b);
        }

        string ans = "";

        // convert baseStr
        for (char ch : baseStr) {
            int root = find(ch - 'a');
            ans += char(root + 'a');
        }

        return ans;
    }
};