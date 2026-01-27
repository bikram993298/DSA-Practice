class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        const int INF = 1e9;
        // two distacnes vector so that track the second minimam disact
        vector<int> dist1(n + 1, INF), dist2(n + 1, INF);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 1});
        // pushed time and node 
        dist1[1] = 0;
        // dsictances giev distances

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            for (int v : adj[u]) {
                int nt = t;

                // traffic light check
 // time taken to to traverse one edge time and intially green light then red light totoal time modulo chnage if odd then red other wise green,,now if somehow it comes red or 1 means you hve to weight till green               
                if ((nt / change) % 2 == 1) {
                    nt = (nt / change + 1) * change;
                }

                nt += time;
                // time taken to traverse oone edge

                if (nt < dist1[v]) {
                    //if u got least timethat dist then update like second maxjmum in array
                    dist2[v] = dist1[v];
                    dist1[v] = nt;
                    pq.push({nt, v});
                }
                // else can time is graert than dist1 and but less than dist2
                else if (nt > dist1[v] && nt < dist2[v]) {
                    dist2[v] = nt;
                    pq.push({nt, v});
                }
            }
        }

        return dist2[n];
    }
};
