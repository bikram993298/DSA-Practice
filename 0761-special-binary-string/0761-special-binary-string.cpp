//Approach : (Recursion)
//T.C : ~O(n^2)
//S.C : O(n) stack space and to store special substrings
class Solution {
public:

    string solve(string s) {
        vector<string> blocks;

        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // found a valid special substring
            if (count == 0) {
                // recurse on inner part
                string inner = solve(s.substr(start + 1, i - start - 1));

                blocks.push_back("1" + inner + "0");

                start = i + 1;
            }
        }

        // sort in descending order
        sort(blocks.begin(), blocks.end(), greater<string>());

        // merge
        string res = "";
        for (auto &b : blocks) res += b;

        return res;
    }

    string makeLargestSpecial(string s) {
        return solve(s);
    }
};