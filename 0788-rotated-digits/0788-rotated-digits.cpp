class Solution {
public:
 map<char, char> mp;
    int rotate(int n) {
        // 1 2 5
        // 1  5    2
        // o(n)
        int ans1 = 0;
        string res = "";
         string s = to_string(n);
        for (int i = 0; i < s.size(); i++) {
            if (!mp.count(s[i])) {
                return -1;
            }
            res += mp[s[i]];
        }
        ans1 = stoi(res);
        return ans1;
    }
    int rotatedDigits(int n) {
        // 0 ->0
        // 1->1
        // 2->5
        // 5->2
        // 6->9
        // brute force
        // fro loop 1->n  o(n)
        // under the for loop we can use 10000 o(4) loop agian and find the
        // roated number and compare if it is smae or not
        // 1 0 0
        // 1 0 0 not valid
        int ans = 0;
       

        mp[0 + '0'] = '0';
        mp[1 + '0'] = '1';
        mp[2 + '0'] = '5';
        

       
        mp[5 + '0'] = '2';
        mp[6 + '0'] = '9';
       
        mp[8 + '0'] = '8';
        mp[9 + '0'] = '6';
        
        for (int i = 1; i <= n; i++) {
            int num = i;
            // 1 4 3
            int rotated = rotate(num);
            if (rotated == -1) {
                continue;
            }
            if (num != rotated) {
                ans++;
            }
        }
         return ans;
    }
   

};
