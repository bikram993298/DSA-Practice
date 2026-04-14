class Solution {
public:
    typedef pair<int, char> P;
    
    string reorganizeString(string s) {
        int n = s.length();
        
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch-'a']++;
   // check if not psoosible
            if(count[ch-'a'] > (n+1)/2)
                return "";
        }
        
        priority_queue<P, vector<P>> pq;
        // add all character those oresent in max heap
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] > 0) {
                pq.push({count[ch-'a'], ch});

            }
         }
        
        string result = "";
        // do do karke pop add akrernge beeacuse somehow vvvvll a b c d if  v=4 then after decreasing 1 adian v=3 again add we need two dfferent so add two pop
        while(pq.size() >= 2) {
            auto P1 = pq.top(); 
            pq.pop();
            
            auto P2 = pq.top();
            pq.pop();
            
            result.push_back(P1.second);
            result.push_back(P2.second);
            
            P1.first--;
            P2.first--;
            
            if(P1.first > 0)
                pq.push(P1);
            
            if(P2.first > 0)
                pq.push(P2);
        }
        // it can happen after two pop single remains so checl
        if(!pq.empty())
            result.push_back(pq.top().second);
        
        return result;
    }
};