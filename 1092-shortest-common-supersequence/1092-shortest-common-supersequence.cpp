


class Solution {
public:
 vector<vector<int>> dp;

    int solve(int i,int j,string&str1,string& str2){
      if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];      // memo check

    if (str1[i - 1] == str2[j - 1]) {
        return dp[i][j] = 1 + solve(i - 1, j - 1, str1, str2);
    } else {
        return dp[i][j] = max(
            solve(i, j - 1, str1, str2),
            solve(i - 1, j, str1, str2)
        );
    }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        dp.resize(m + 1, vector<int>(n + 1, -1));
        solve(m,n,str1,str2);

      
        // Build the shortest supersequence
        int i = m, j = n;
        string result = "";
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // here dfieenfetect from lcs ,,in lcs we dont add iuncomon strigns 
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }
        // if some strign empty ad other is bikram then you have to scs will be bikram bu tl cs empty so for scs take this codniton

        while (i > 0) result += str1[--i];
        while (j > 0) result += str2[--j];

        reverse(result.begin(), result.end());
        return result;
    }
};