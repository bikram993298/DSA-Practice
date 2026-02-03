/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
   
    // Step 2: Perform BFS from start node
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;


        function<void(TreeNode* node)> buildGraph=[&](TreeNode* node){
             if (!node) return;
        
        if (node->left) {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val); // bidirectional
            buildGraph(node->left);
        }

        if (node->right) {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val); // bidirectional
            buildGraph(node->right);
        }

        };
        buildGraph(root); // build graph from binary tree

        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        int minutes = -1;  // start from -1, first level is minute 0

        while (!q.empty()) {
            int sz = q.size();
            minutes++;

            for (int i = 0; i < sz; ++i) {
                int curr = q.front();
                q.pop();

                for (int neighbor : adj[curr]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return minutes;
    }
};



// class Solution {
// public:
//     unordered_map<TreeNode*, TreeNode*> parent;

//     int amountOfTime(TreeNode* root, int start) {

//         // Step 1: build parent mapping
//         function<void(TreeNode*)> buildgraph = [&](TreeNode* node) {
//             if (!node) return;

//             if (node->left) {
//                 parent[node->left] = node;
//                 buildgraph(node->left);
//             }
//             if (node->right) {
//                 parent[node->right] = node;
//                 buildgraph(node->right);
//             }
//         };

//         buildgraph(root);

//         // Step 2: find start node
//         TreeNode* startNode = nullptr;
//         function<void(TreeNode*)> findStart = [&](TreeNode* node) {
//             if (!node) return;
//             if (node->val == start) startNode = node;
//             findStart(node->left);
//             findStart(node->right);
//         };

//         findStart(root);

//         // Step 3: BFS infection spread
//         unordered_set<TreeNode*> visited;
//         queue<TreeNode*> q;

//         q.push(startNode);
//         visited.insert(startNode);

//         int minutes = -1;

//         while (!q.empty()) {
//             int sz = q.size();
//             minutes++;

//             for (int i = 0; i < sz; i++) {
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 if (curr->left && !visited.count(curr->left)) {
//                     visited.insert(curr->left);
//                     q.push(curr->left);
//                 }

//                 if (curr->right && !visited.count(curr->right)) {
//                     visited.insert(curr->right);
//                     q.push(curr->right);
//                 }

//                 if (parent.count(curr) && !visited.count(parent[curr])) {
//                     visited.insert(parent[curr]);
//                     q.push(parent[curr]);
//                 }
//             }
//         }

//         return minutes;
//     }
// };



















