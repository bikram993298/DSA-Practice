class Solution {
public:
       vector<string> res;
     
    void dfs(int idx, const string &s, unordered_set<string> &dict,
             vector<string> &path) {
        if (idx == s.size()) {
            // Join words in path to form a sentence
            string sentence = "";
            for (int i = 0; i < path.size(); ++i) {
                if (i > 0) sentence += " ";
                sentence += path[i];
            }
            res.push_back(sentence);
            return;
        }

        for (int end = idx ; end < s.size(); ++end) {
            string word = s.substr(idx, end - idx+1);
            if (dict.count(word)) {
                path.push_back(word);       // choose this word
                dfs(end+1, s, dict, path); // recurse
                path.pop_back();             // backtrack
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
    
        vector<string> path; // stores words in the current sentence
        dfs(0, s, dict, path);
        return res;
    }


};

// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         unordered_map<int, vector<string>> memo;
//         return dfs(0, s, dict, memo);
//     }
    
// private:
//     vector<string> dfs(int idx, const string &s, unordered_set<string> &dict,
//                        unordered_map<int, vector<string>> &memo) {
//         if (memo.count(idx)) return memo[idx];

//         vector<string> res;
//         if (idx == s.size()) {
//             res.push_back(""); // base case: empty string
//             return res;
//         }
//          string word="";
//         for (int end = idx ; end <s.size(); ++end) {
           

//             word.push_back(s[end]);
//             if (dict.count(word)) {
//                 vector<string> sublist = dfs(end+1, s, dict, memo);
//                 for (const string &sub : sublist) {
//                     res.push_back(word + (sub.empty() ? "" : " " + sub));
//                 }
//             }
//         }

//         return memo[idx] = res; // store result in memo
//     }
// };
