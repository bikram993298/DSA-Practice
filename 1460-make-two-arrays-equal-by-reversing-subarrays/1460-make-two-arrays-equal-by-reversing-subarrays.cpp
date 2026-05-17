// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         // just hink about bubbble sort adjance tosrt means 2 aubtring aort
        
//     }
// };
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        return target == arr;
    }
};