class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int j= 0;   //track the write the number how may times it occur
        int i = 0;     

        while (i < n) {
            char curr = chars[i];
            int count = 0;

            // Count consecutive same characters
            while (i < n && chars[i] == curr) {
                i++;
                count++;
            }

            // Write the character
            chars[j] = curr;
            j++;

            //if count ==1 then olny write the hcrach and if more then i have to maek tsring of that and add one by one
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[j] = c;
                    j++;
                }
            }
        }

        // write is the new length of compressed array
        return j;
    }
};
