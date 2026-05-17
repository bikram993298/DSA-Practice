// // class Solution {
// // public:
// //     int isPrefixOfWord(string sentence, string searchWord) {
// //         // i will traverse thorght he string and i will create map where each possible prefix i will store,and for making each possible prefix i have to creater another epmty string ,,when i encounter space i will makeit empty agian then, if not space add in the same string ,,ehn space push map and make empty string ,,,now chek burg exist or not
        
// //     }
// // };
// class Solution {
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {

//         map<string,int> mp;

//         string temp = "";

//         int idx = 1;

//         for (int i = 0; i < sentence.size(); i++) {

//             if (sentence[i] == ' ') {

//                 string prefix = "";

//                 // store all prefixes
//                 for (int j = 0; j < temp.size(); j++) {

//                     prefix += temp[j];

//                     // store first occurrence only
//                     if (mp.find(prefix) == mp.end())
//                         mp[prefix] = idx;
//                 }

//                 idx++;

//                 temp = "";
//             }
//             else {

//                 temp += sentence[i];
//             }
//         }

//         // last word process
//         string prefix = "";

//         for (int j = 0; j < temp.size(); j++) {

//             prefix += temp[j];

//             if (mp.find(prefix) == mp.end())
//                 mp[prefix] = idx;
//         }

//         if (mp.find(searchWord) != mp.end())
//             return mp[searchWord];

//         return -1;
//     }
// };
// no appraoch is see for evey word first  serachword.sieze is substring is smae or not
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        string word = "";

        int index = 1;

        for (int i = 0; i <= sentence.size(); i++) {

            // word completed
            if (i == sentence.size() || sentence[i] == ' ') {

                // check prefix
                if (word.find(searchWord) == 0) {
                    return index;
                }

                index++;

                word = "";
            }
            else {

                word += sentence[i];
            }
        }

        return -1;
    }
};