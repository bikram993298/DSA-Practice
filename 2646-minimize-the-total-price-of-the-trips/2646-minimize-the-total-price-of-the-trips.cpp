class Solution {
public:

    bool dfsCount(int node, int parent, int target,
                  vector<vector<int>>& adj,
                  vector<int>& freq){

        if(node == target){
            freq[node]++;
            return true;
        }

        for(int nei : adj[node]){
            if(nei == parent) continue;

            if(dfsCount(nei, node, target, adj, freq)){
                freq[node]++;
                return true;
            }
        }

        return false;
    }

    pair<long long,long long> dfsDP(int node,
                                    int parent,
                                    vector<vector<int>>& adj,
                                    vector<int>& freq,
                                    vector<int>& price){

        long long notHalf = 1LL * freq[node] * price[node];
        long long half = 1LL * freq[node] * price[node]/2;

        for(int nei : adj[node]){

            if(nei == parent) continue;

            auto child = dfsDP(nei, node, adj, freq, price);

            notHalf += min(child.first, child.second);

            half += child.first;
        }

        return {notHalf, half};
    }

    int minimumTotalPrice(int n,
                          vector<vector<int>>& edges,
                          vector<int>& price,
                          vector<vector<int>>& trips){

        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> freq(n,0);

        for(auto &t : trips){
            dfsCount(t[0], -1, t[1], adj, freq);
        }

        auto res = dfsDP(0, -1, adj, freq, price);

        return min(res.first, res.second);
    }
};
