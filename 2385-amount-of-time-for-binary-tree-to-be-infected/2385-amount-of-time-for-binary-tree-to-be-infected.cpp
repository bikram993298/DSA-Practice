class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    int amountOfTime(TreeNode* root, int start) {

        // Step 1: build parent mapping
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

        // Step 2: find start node
        TreeNode* startNode = nullptr;
        function<void(TreeNode*)> findStart = [&](TreeNode* node) {
            if (!node) return;
            if (node->val == start) startNode = node;
            findStart(node->left);
            findStart(node->right);
        };

        findStart(root);

        // Step 3: BFS infection spread
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(startNode);
        visited.insert(startNode);

        int minutes = -1;

        while (!q.empty()) {
            int sz = q.size();
            minutes++;

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                if (parent.count(curr) && !visited.count(parent[curr])) {
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
        }

        return minutes;
    }
};
