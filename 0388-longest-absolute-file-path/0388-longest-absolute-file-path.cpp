class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, string> mp; // depth → full path
        int ans = 0;

        stringstream ss(input);
        string line;

        while (getline(ss, line, '\n')) {

            // 1️⃣ count depth
            int depth = 0;
            while (line[depth] == '\t') depth++;

            // 2️⃣ get name
            string name = line.substr(depth);

            // 3️⃣ build path
            if (depth == 0) {
                mp[depth] = name;
            } else {
                mp[depth] = mp[depth - 1] + "/" + name;
            }

            // 4️⃣ check file
            if (name.find('.') != string::npos) {
                ans = max(ans, (int)mp[depth].size());
            }
        }

        return ans;
    }
};