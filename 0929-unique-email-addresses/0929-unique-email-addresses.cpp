// Time: O(N * L)
// Space: O(N * L)
// main thing in local neame after + ingone so break,if . then merge and domain name willbe same after @
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for (string email : emails) {
            int atPos = email.find('@');
            
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos);

            string cleanLocal = "";
            
            for (char c : local) {
                if (c == '+') break;
                if (c != '.') {
                    cleanLocal += c;
                }
            }

            st.insert(cleanLocal + domain);
        }

        return st.size();
    }
};