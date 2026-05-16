// class Solution {
// public:
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         //4->1
//         //3->3
//         //1->2
//         //2->1
//         // in map store frequency,value,,,then from map keep minizing till k gets zero and count map size
        
//     }
// };
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int> mp;

        // count frequency
        for(int x : arr) {
            mp[x]++;
        }

        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it : mp) {
            pq.push(it.second);
        }

        int unique = mp.size();

        // remove smallest frequencies first
        while(!pq.empty()) {

            int freq = pq.top();

            if(k >= freq) {

                k -= freq;
                unique--;

                pq.pop();
            }
            else {
                break;
            }
        }

        return pq.size();
    }
};