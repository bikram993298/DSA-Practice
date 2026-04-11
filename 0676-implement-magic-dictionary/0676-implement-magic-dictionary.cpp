class MagicDictionary {
public:
    vector<string> dict;

    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        dict = dictionary;
    }

    bool search(string word) {
        for (string &s : dict) {
            if (s.size() != word.size()) continue;

            int diff = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != word[i]) diff++;
                if (diff > 1) break;
            }

            if (diff == 1) return true;
        }
        return false;
    }
};