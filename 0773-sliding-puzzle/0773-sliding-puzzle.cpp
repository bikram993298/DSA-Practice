class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (auto &row : board) {
            for (int x : row) {
                start += to_string(x);
            }
        }
// we need the row* coloum as string 
// we need to use bfs wvey state as node adn adjaency will be a cording to tier
        string target = "123450";

        // neighbors for each index
        vector<vector<int>> adj = {
            {1,3},    // 0
            {0,2,4},  // 1
            {1,5},    // 2
            {0,4},    // 3
            {1,3,5},  // 4
            {2,4}     // 5
        };

        queue<string> q;
        unordered_set<string> vis;

        q.push(start);
        vis.insert(start);

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string curr = q.front(); q.pop();

                if (curr == target) return steps;
                // find zero er incex then find its neigbour and create another string so that not effect in real string 

                int zero = curr.find('0');

                for (int nei : adj[zero]) {
                    string next = curr;
                    swap(next[zero], next[nei]);

                    if (!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};