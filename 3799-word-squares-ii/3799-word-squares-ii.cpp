class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        auto s = words; // Store 
       sort(s.begin(),s.end());
        vector<vector<string>> result;
        int n = words.size();
    
        
       // try brute force
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n;j++) {
                //  top[0] == left[0]
                if (i != j && s[i][0] == s[j][0]) {
                    for (int k = 0; k < n; k++) {
                        //  top[3] == right[0]
                        if (k!= i && k != j && s[i][3] == s[k][0]) {
                            for (int l = 0; l < n; ++l) {
                                //  bottom[0] == left[3]
                                //  bottom[3] == right[3]
                                if (l != i && l != j && l != k && 
                                    s[l][0] == s[j][3] && 
                                    s[l][3] == s[k][3]) {
                                        // vector<string> ans;
                                        // ans.push_back(s[i]);
                                        //  ans.push_back(s[j]);
                                        //   ans.push_back(s[k]);
                                        //    ans.push_back(s[l]);
                                        // sort(ans.begin(),ans.end());
                                        // cout<<ans<<endl;
                                        //for lexicographically ascendind order and fill then codinitins 4 condition, means  ["able","area","echo","also"],["area","able","also","echo"]]
                                        //means able come before the second ouput area  so we have initially sort 


                                        //if u dont sort then oupt will come same but position can differen  see  carefully fo rthese tyoe of ascendig order output we have to make sort 
//                  Output
// [["dooe","diia","exxj","avvj"],["diia","dooe","avvj","exxj"]]
// Expected
// [["diia","dooe","avvj","exxj"],["dooe","diia","exxj","avvj"]]
                       

                                     result.push_back({s[i], s[j], 
                                                     s[k], s[l]});
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};