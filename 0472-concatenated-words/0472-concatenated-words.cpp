class Solution {
public:

    unordered_set<string> st;

    unordered_map<string, bool> memo;

    bool solve(string word) {

        if(memo.count(word))
            return memo[word];

        for(int i = 1; i < word.size(); i++) {

            string left = word.substr(0, i);
            string right = word.substr(i);

            // left exists
            if(st.count(left)) {

                // right exists directly
                if(st.count(right)) {
                    return memo[word] = true;
                }

                // or recursively form right
                if(solve(right)) {
                    return memo[word] = true;
                }
            }
        }

        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        for(string &w : words)
            st.insert(w);

        vector<string> ans;

        for(string &word : words) {

            st.erase(word); // avoid self usage

            if(solve(word))
                ans.push_back(word);

            st.insert(word);
        }

        return ans;
    }
};