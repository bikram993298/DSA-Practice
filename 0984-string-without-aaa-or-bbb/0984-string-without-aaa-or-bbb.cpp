class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res = "";

        while (a > 0 || b > 0) {

            int n = res.size();

           // mian idechecl last two  if eqaul,,then put another if not equal put maxium chr

            if (n >= 2 && res[n-1] == res[n-2]) {
                // last two same → force opposite
                if (res[n-1] == 'a') {
                    res += 'b';
                    b--;
                } else {
                    res += 'a';
                    a--;
                }
            }
            else {
                // choose larger count
                if (a >= b) {
                    if (a > 0) {
                        res += 'a';
                        a--;
                    } else {
                        res += 'b';
                        b--;
                    }
                } else {
                    if (b > 0) {
                        res += 'b';
                        b--;
                    } else {
                        res += 'a';
                        a--;
                    }
                }
            }

           
        }

        return res;
    }
};