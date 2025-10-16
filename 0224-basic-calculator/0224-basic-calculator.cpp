class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                int val = 0;
                while (i < s.size() && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--; // step back
                sum += sign * val;
            } 
            else if (ch == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            } 
            else if (ch == ')') {
                int prevSign = st.top(); st.pop();
                int prevSum = st.top(); st.pop();
                sum = prevSum + prevSign * sum;
            } 
            else if (ch == '+') {
                sign = 1;
            } 
            else if (ch == '-') {
                sign = -1;
            } 
            else if (ch == ' ') {
                continue; // skip spaces
            }
        }

        return sum;
    }
};
