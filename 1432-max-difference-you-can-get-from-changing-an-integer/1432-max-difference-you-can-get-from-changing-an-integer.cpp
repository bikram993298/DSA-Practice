class Solution {
public:
// main ideaFor max: replace first non-9 digit with 9 and replace all occurences of that digit with 9. For min: if first digit≠1, replace it with 1; else find first non-0 non-1 digit and replace with 0.
    int maximum(int num) {

        string s = to_string(num);

        char ch = ' ';

        // first non-9 digit
        for (char c : s) {

            if (c != '9') {
                ch = c;
                break;
            }
        }

        // replace with 9
        if (ch != ' ') {

            for (char &c : s) {

                if (c == ch)
                    c = '9';
            }
        }

        return stoi(s);
    }

    int minimum(int num) {

        string s = to_string(num);

        char ch = ' ';

        // case 1
        if (s[0] != '1') {

            ch = s[0];

            for (char &c : s) {

                if (c == ch)
                    c = '1';
            }
        }

        // case 2
        else {

            for (int i = 1; i < s.size(); i++) {

                if (s[i] != '0' && s[i] != '1') {

                    ch = s[i];
                    break;
                }
            }

            if (ch != ' ') {

                for (char &c : s) {

                    if (c == ch)
                        c = '0';
                }
            }
        }

        return stoi(s);
    }

    int maxDiff(int num) {

        return maximum(num) - minimum(num);
    }
};