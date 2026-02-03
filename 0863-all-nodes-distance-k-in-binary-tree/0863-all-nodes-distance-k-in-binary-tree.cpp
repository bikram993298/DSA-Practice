class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    // for AXPAANTION SEE HARD COPY WHITE SRASWATI KHATA

    // DFS to build parent mapping (NO QUEUE)
    void buildParent(TreeNode* root, TreeNode* par = nullptr) {
        if (!root) return;

        parent[root] = par;
        buildParent(root->left, root);
        buildParent(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) break;

            dist++;

            for (int i = 0; i < size; i++) {
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
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
