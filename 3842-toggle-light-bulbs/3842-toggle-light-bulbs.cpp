class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {                                                                                                                    int n=bulbs.size();


    map<int,int>mp;


    for(int i=0;i<n;i++){
        mp[bulbs[i]]++;
    }


    vector<int> ans;
    for(auto it:mp){
        if(it.second%2==1){
            ans.push_back(it.first);
        }
    }
        

        return ans;
    }
};