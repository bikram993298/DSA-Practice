// // class Solution {
// // public:
// // // her ei nt his question you are given min number of steps,,not min cost there will be many cost use bfs
// //     int minJumps(vector<int>& arr) {
        
// //     }
// // };
// class Solution {
// public:

//     int minJumps(vector<int>& arr) {

//         int n = arr.size();

//         if(n == 1)
//             return 0;

//         unordered_map<int, vector<int>> mp;

//         // value -> indices
//         for(int i = 0; i < n; i++) {
//             mp[arr[i]].push_back(i);
//         }

//         // adjacency list
//         vector<vector<int>> adj(n);

//         for(int i = 0; i < n; i++) {

//             // i-1
//             if(i - 1 >= 0)
//                 adj[i].push_back(i - 1);

//             // i+1
//             if(i + 1 < n)
//                 adj[i].push_back(i + 1);

//             // same value indices
//             for(int idx : mp[arr[i]]) {

//                 if(idx != i)
//                     adj[i].push_back(idx);
//             }
//         }

//         // BFS
//         queue<int> q;
//         vector<int> vis(n, 0);

//         q.push(0);
//         vis[0] = 1;

//         int steps = 0;

//         while(!q.empty()) {

//             int sz = q.size();

//             while(sz--) {

//                 int node = q.front();
//                 q.pop();

//                 if(node == n - 1)
//                     return steps;

//                 for(int nei : adj[node]) {

//                     if(!vis[nei]) {

//                         vis[nei] = 1;
//                         q.push(nei);
//                     }
//                 }
//             }

//             steps++;
//         }

//         return -1;
//     }
// };
// Do NOT build adjacency list.

// Instead:

// during BFS
// directly fetch same-value neighbors from hashmap

// This creates edges only when needed.

class Solution {
public:

    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                int idx = q.front();
                q.pop();

                if(idx == n - 1)
                    return steps;

                // left
                if(idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }

                // right
                if(idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }

                // same value jumps
                for(int next : mp[arr[idx]]) {

                    if(!vis[next]) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }

                // IMPORTANT
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};