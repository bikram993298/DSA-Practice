class Solution {
public:

    vector<string> getWords(string s) {

        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word) {
            words.push_back(word);
        }

        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> w1 = getWords(sentence1);
        vector<string> w2 = getWords(sentence2);

        // Always make w1 the smaller sentence
        if(w1.size() > w2.size())
            swap(w1, w2);

        int i = 0;
        int j = 0;

        // match prefix
        while(i < w1.size() && w1[i] == w2[i])
            i++;

        // match suffix
        while(j < w1.size() - i &&
              w1[w1.size()-1-j] == w2[w2.size()-1-j])
            j++;

        return i + j >= w1.size();
    }
};
