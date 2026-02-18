class Solution {
public:

    vector<vector<pair<int,int>>> adj;
    vector<int> need;
    vector<int> answer;

    // DFS returns whether this node still needs toggle after fixing children
    bool dfs(int node, int parent) {

        bool cur = need[node];

        for(auto &it : adj[node]){

            int child = it.first;
            int edgeIndex = it.second;

            if(child == parent) continue;

            bool childNeed = dfs(child, node);

            // if child still needs toggle, toggle this edge
            if(childNeed) {

                answer.push_back(edgeIndex);

                // toggling edge flips current node parity
                cur ^= 1;
            }
        }

        return cur;
    }

    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {

        adj.resize(n);
        need.resize(n);

        // build adjacency list
        for(int i=0;i<edges.size();i++){

            int u =edges[i][0];
            int v =edges[i][1];

            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }

        // compute need  array
        for(int i=0;i<n;i++) {

            need[i] =(start[i]!=target[i]);
        }

     
        bool rootNeed = dfs(0, -1);

        //if root still needs toggle → impossible
        if(rootNeed)
            return {-1};

        // return sorted edge indices
        sort(answer.begin(), answer.end());

        return answer;
    }
};
