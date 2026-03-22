class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> l(n), r(n);

        l[0] = 0;
        for(int i = 1; i < n; i++)
            l[i] = max(l[i-1], h[i-1]);

        r[n-1] = 0;
        for(int i = n-2; i >= 0; i--)
            r[i] = max(r[i+1], h[i+1]);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int w = min(l[i], r[i]) - h[i];
            if(w > 0) ans += w;
        }
        return ans;
    }
};