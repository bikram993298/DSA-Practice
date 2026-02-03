class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        function<void(TreeNode*)> buildgraph = [&](TreeNode* node) {
            if (!node) return;

            if (node->left) {
                parent[node->left] = node;
                buildgraph(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                buildgraph(node->right);
            }
        };

        buildgraph(root);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) break;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
// after first levle or in fiest iteration all 0th level in ques then 2nd level then h=third  level like wise so for 3 rd level nodes we need if ist==3 then break and all remaining in ques will be third
        return ans;
    }
};
