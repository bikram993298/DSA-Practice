class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Check condition
        for (int i = 0; i < n; i++) {
            long long len = right[i] - left[i] - 1;
            if ((long long)nums[i] * len > threshold)
                return len;
        }

        return -1;
    }
};
