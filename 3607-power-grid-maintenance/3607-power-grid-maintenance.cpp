class Solution {
public:



 class DSU {
    public:
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n + 1);
            sz.assign(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]); 
            return parent[x];
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;

         
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    };

   

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
         DSU dsu(c);
        for (auto &e : connections) {
            dsu.unite(e[0], e[1]);
        }

       
        unordered_map<int, set<int>> comp;
        for (int i = 1; i <= c; i++) {
            comp[dsu.find(i)].insert(i);
        }

        vector<int> ans;

    
        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if (type == 2) {
                // station goes offline so in connec ted component  you removed than node 
                comp[root].erase(x);
            } else {
                // maintenance check
                if (comp[root].count(x)) {
                    ans.push_back(x);
                } else {
                    if (comp[root].empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(*comp[root].begin());
                }
            }
        }

        return ans;
        
    }
};