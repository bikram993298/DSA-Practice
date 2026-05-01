// class Solution {
// public:
//     int lengthLongestPath(string input) {
//         unordered_map<int, string> mp; // depth → full path
//         int ans = 0;

//         stringstream ss(input);
//         string line;

//         while (getline(ss, line, '\n')) {

//             // 1️⃣ count depth
//             int depth = 0;
//             while (line[depth] == '\t') depth++;

//             // 2️⃣ get name
//             string name = line.substr(depth);

//             // 3️⃣ build path
//             if (depth == 0) {
//                 mp[depth] = name;
//             } else {
//                 mp[depth] = mp[depth - 1] + "/" + name;
//             }

//             // 4️⃣ check file
//             if (name.find('.') != string::npos) {
//                 ans = max(ans, (int)mp[depth].size());
//             }
//         }

//         return ans;
//     }
// };
// here tyou are storing the wholse string according to depth .. o(n^2) complexcyty of copying now yo can store lentgh
class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> mp; // depth → path length
        int ans = 0;

        stringstream ss(input);
        string line;

        while (getline(ss, line, '\n')) {

            // 1️⃣ count depth
            int depth = 0;
            while (line[depth] == '\t') depth++;

            // 2️⃣ get name
            string name = line.substr(depth);
            int len = name.size();

            // 3️⃣ if file
            if (name.find('.') != string::npos) {
                // total length = parent + file name
                int total = (depth == 0 ? 0 : mp[depth - 1]) + len;
                ans = max(ans, total);
            } 
            else {
                // directory → store length + '/'
                if (depth == 0) {
                    mp[depth] = len + 1;
                } else {
                    mp[depth] = mp[depth - 1] + len + 1;
                }
            }
        }

        return ans;
    }
};