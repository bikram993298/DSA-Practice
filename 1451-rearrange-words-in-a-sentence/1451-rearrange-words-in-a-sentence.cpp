class Solution {
public:
    string arrangeWords(string text) {

        text[0] = tolower(text[0]);

        vector<pair<string, pair<int,int>>> v;

        string word = "";

        int idx = 0;

        // extract words manually
        for (int i = 0; i < text.size(); i++) {

            if (text[i] == ' ') {

                v.push_back({word, {word.size(), idx}});

                idx++;

                word = "";
            }
            else {

                word += text[i];
            }
        }

        // last word
        v.push_back({word, {word.size(), idx}});

        sort(v.begin(), v.end(),
            [](auto &a, auto &b) {

                // smaller length first
                if (a.second.first != b.second.first)
                    return a.second.first < b.second.first;

                // same length -> original order
                return a.second.second < b.second.second;
            });

        string ans = "";

        for (int i = 0; i < v.size(); i++) {

            ans += v[i].first;

            if (i != v.size() - 1)
                ans += " ";
        }

        ans[0] = toupper(ans[0]);

        return ans;
    }
};