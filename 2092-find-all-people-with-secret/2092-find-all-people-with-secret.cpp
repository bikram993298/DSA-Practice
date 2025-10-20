class Solution {
public:
    vector<int> parent, rankk;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rankk[x] < rankk[y]) swap(x, y);
        parent[y] = x;
        if (rankk[x] == rankk[y]) rankk[x]++;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        rankk.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        // Person 0 and firstPerson initially share secret
        unite(0, firstPerson);

        // Sort meetings by time
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];
            vector<int> participants;

            // Collect all meetings at same time
            while (i < meetings.size() && meetings[i][2] == t) {
                int a = meetings[i][0], b = meetings[i][1];
                unite(a, b);
                participants.push_back(a);
                participants.push_back(b);
                i++;
            }

            // After all unions for time t, reset components without connection to 0
            unordered_set<int> uniqueP(participants.begin(), participants.end());
            for (int p : uniqueP) {
                if (find(p) != find(0))
                    parent[p] = p; // reset
            }
        }

        // Collect all people connected to person 0
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0)) res.push_back(i);
        }
        return res;
    }
};
