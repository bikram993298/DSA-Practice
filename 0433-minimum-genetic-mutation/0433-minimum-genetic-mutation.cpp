// class Solution {
// public:
//     int minMutation(string startGene, string endGene, vector<string>& bank) {
//         // we have given startgene to endgene in one operation we can do one char to another,,that should be in bank,,
//         // so here we can make graph withnodes nad endges and find bfs to find shortest,
//         // start node=startGene,,, let for every char change to A ,C ,G, T and see if it is in the set bank if yes then push back,,so thus we will make directed edge
//     }
// };
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());

        // If endGene is not present, impossible to reach
        if (st.find(endGene) == st.end()) return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            // Reached target
            if (curr == endGene) return steps;

            for (int i = 0; i < curr.size(); i++) {
                char original = curr[i];
                string temp=curr;
                // skip the currnet elemnt

                for (char ch : genes) {
                    if (ch == original) continue;

                    temp[i] = ch;

                    // Valid mutation must exist in bank
                    if (st.find(temp) != st.end()) {
                        q.push({temp, steps + 1});
                        // instead of viisted array use bank set as visited
                        st.erase(temp); // mark visited
                    }
                }

                // curr[i] = original; // restore
            }
        }

        return -1;
    }
};