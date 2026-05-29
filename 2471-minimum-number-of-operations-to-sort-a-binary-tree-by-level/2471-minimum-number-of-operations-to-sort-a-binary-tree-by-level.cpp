class Solution {
public:

    int minSwaps(vector<int>& vec) {

        int n = vec.size();

        vector<int> sortedVec = vec;

        sort(sortedVec.begin(), sortedVec.end());

        unordered_map<int,int> mp;

        for(int i=0; i<n; i++) {
            mp[vec[i]] = i;
        }

        int cnt = 0;

        for(int i=0; i<n; i++) {

            if(vec[i] != sortedVec[i]) {

                int idx = mp[sortedVec[i]];

                swap(vec[i], vec[idx]);
                // after swap update real indexes

                mp[vec[idx]] = idx;
                mp[vec[i]] = i;

                cnt++;
            }
        }

        return cnt;
    }

    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;

        q.push(root);

        int ans = 0;

        while(!q.empty()) {

            int sz = q.size();

            vector<int> level;

            for(int i=0; i<sz; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            ans += minSwaps(level);
        }

        return ans;
    }
};