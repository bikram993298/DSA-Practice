class Solution {
public:
    int numWays(string s) {

        const long long MOD = 1e9 + 7;

        long long total_1 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') total_1++;
        }

        if(total_1 % 3 != 0) return 0;

        if(total_1 == 0){
            long long n = s.size();
            return ((n-1)*(n-2)/2) % MOD;
        }

        total_1 = total_1 / 3;

        int cnt = 0;
        int pos1 = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') cnt++;
            if(cnt == total_1){
                pos1 = i;
                break;
            }
        }

        int cnt_0 = 0;
        int i = pos1 + 1;
        while(i < s.size() && s[i] == '0'){
            cnt_0++;
            i++;
        }

        cnt = 0;
        int pos2 = 0;

      
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '1') cnt++;
            if(cnt == total_1){
                pos2 = i;
                break;
            }
        }

        int cnt_0l = 0;
        i = pos2 - 1;
        while(i >= 0 && s[i] == '0'){
            cnt_0l++;
            i--;
        }

        return ((long long)(cnt_0 + 1) * (cnt_0l + 1)) % MOD;
    }
};