// class Solution {
// public:
//     vector<string> getFolderNames(vector<string>& names) {
//         //for each word go to inset into map till() bracket then,next check before () is inserted or not
//         // gta->0,1,2
        
//     }
// };
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        
        unordered_map<string,int> mp;

        vector<string> ans;

        for(string name : names) {

            // name not used before
            if(mp.count(name) == 0) {

                ans.push_back(name);

                mp[name] = 1;
            }
            else {

                int k = mp[name];
                

                string newName;

                // find unique name
                while(true) {

                    newName = name + "(" + to_string(k) + ")";

                    if(mp.count(newName) == 0)
                        break;

                    k++;
                }

                ans.push_back(newName);

                mp[name] = k ;

                mp[newName] = 1;
            }
        }

        return ans;
    }
};