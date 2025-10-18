class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        //for verfy request we are checking is nay server is free for that we used set freeservers thT GIVE IF  i%k server is free if that do not exist then i+1%k so we are using set and lower bound to find if goesto end then it.negin()
        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> count(k, 0);
        
        for (int i = 0; i < arrival.size(); i++) {
            long long start = arrival[i];
            long long end = start + load[i];

            // Free up servers that have finished before 'start'
            while (!busy.empty() && busy.top().first <= start) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }

            if (freeServers.empty()) continue; // all busy → drop request

            int target = i % k;
            // Find next available server ≥ target
            auto it = freeServers.lower_bound(target);
            if (it == freeServers.end()) it = freeServers.begin(); // wrap around

            int server = *it;
            freeServers.erase(it);
            count[server]++;
            busy.push({end, server});
        }

        // Find max count
        int maxReq = *max_element(count.begin(), count.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (count[i] == maxReq) ans.push_back(i);
        }
        return ans;
    }
};
