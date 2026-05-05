class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {

            // 22 10 -20
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                if (!st.empty() && st.top() > 0) {
                    

                        // while (!st.empty() && (st.top() < abs(asteroids[i])))
                        // {
                        //     st.pop();
                        // }
                        while (!st.empty() && st.top() > 0 &&
                               st.top() < abs(asteroids[i])) {
                            st.pop();
                        }
                        if (st.empty() || st.top() < 0) {
                            st.push(asteroids[i]);
                        }
                        //  st.push(asteroids[i]);

                     else if (!st.empty() && st.top() == abs(asteroids[i])) {
                        st.pop();
                        //     if(st.empty()){
                        //     st.push(asteroids[i]);
                        // }

                    } else {
                        // st.tpop bigger
                    }

                } else {
                    st.push(asteroids[i]);
                }

                //   st.push(asteroids[i]);
            }

            //   st.push(asteroids[i]);
        }
        // print the resukt
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};