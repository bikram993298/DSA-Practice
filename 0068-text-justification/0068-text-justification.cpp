class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> lineWords;
        int l = 0; // total length of words (without spaces)

        for (int i = 0; i < words.size(); i++) {
            //lineword=all string that cssn be satisfied in a line
            if (l + words[i].size() + (int)lineWords.size() > maxWidth) {
                int totalSpaces = maxWidth - l;
                //if there is single elemnt then gaps can be zero but  we have to fix the libe as a string and rest spaces on the line so take max of 1 and that devidin will give same
                int gaps = max(1, (int)lineWords.size() - 1);
                int evenSpace = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                string line;
                for (int j = 0; j < lineWords.size(); j++) {
                    line += lineWords[j];
                    if (j < gaps) {
                        //gaps 3 means there is 4 string and 3 gaps
                        //during extra we have to share extra from left 
                        int spaceCount = evenSpace + (j < extra ? 1 : 0);
                        line.append(spaceCount, ' ');
                    }
                }
                ans.push_back(line);
                lineWords.clear();
                l = 0;
            }

            lineWords.push_back(words[i]);
            l += words[i].size();
        }

        // last line - left justified
        string last;
        for (int i = 0; i < lineWords.size(); i++) {
            if (i > 0) last += ' ';
            last += lineWords[i];
        }
        last.append(maxWidth - last.size(), ' ');
        ans.push_back(last);

        return ans;
    }
};
