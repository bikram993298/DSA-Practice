class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return; // already connected

        // union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int countComponents() {
        unordered_set<int> roots;
        for (int i = 0; i < parent.size(); ++i)
            roots.insert(find(i));
        return roots.size();
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2; // number of couples
        DSU dsu(n);

        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i];
            int b = row[i + 1];
            int coupleA = a / 2;
            int coupleB = b / 2;
            dsu.unite(coupleA, coupleB);
        }

        int components = dsu.countComponents();
        return n - components; // swaps needed = total couples - components
    }
};
