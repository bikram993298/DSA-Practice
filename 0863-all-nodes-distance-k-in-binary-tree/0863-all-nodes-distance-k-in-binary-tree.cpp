// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

//         unordered_map<TreeNode*, TreeNode*> parent;

//        function<void(TreeNode* node)> buildGraph=[&](TreeNode* node){
//              if (!node) return;
        
//         if (node->left) {
//             adj[node->val].push_back(node->left->val);
//             adj[node->left->val].push_back(node->val); // bidirectional
//             buildGraph(node->left);
//         }

//         if (node->right) {
//             adj[node->val].push_back(node->right->val);
//             adj[node->right->val].push_back(node->val); // bidirectional
//             buildGraph(node->right);
//         }

//         };

//         buildgraph(root);

//         unordered_set<TreeNode*> visited;
//         queue<TreeNode*> q;

//         q.push(target);
//         visited.insert(target);

//         int dist = 0;

//         while (!q.empty()) {
//             int size = q.size();

//             if (dist == k) break;

//             while (size--) {
//                 TreeNode* node = q.front();
//                 q.pop();

//                 if (node->left && !visited.count(node->left)) {
//                     visited.insert(node->left);
//                     q.push(node->left);
//                 }

//                 if (node->right && !visited.count(node->right)) {
//                     visited.insert(node->right);
//                     q.push(node->right);
//                 }

//                 if (parent.count(node) && !visited.count(parent[node])) {
//                     visited.insert(parent[node]);
//                     q.push(parent[node]);
//                 }
//             }
//             dist++;
//         }

//         vector<int> ans;
//         while (!q.empty()) {
//             ans.push_back(q.front()->val);
//             q.pop();
//         }
// // after first levle or in fiest iteration all 0th level in ques then 2nd level then h=third  level like wise so for 3 rd level nodes we need if ist==3 then break and all remaining in ques will be third
//         return ans;
//     }
// };
// yhis one approach building ajanecy with values and int ot ovector o fint as normal adjancey ans playing wiht the node->val
class Solution {
public:
    unordered_map<int, vector<int>> adj;

    void buildGraph(TreeNode* node) {
        if (!node) return;

        if (node->left) {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            buildGraph(node->left);
        }

        if (node->right) {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            buildGraph(node->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root);

        unordered_set<int> visited;
        queue<int> q;

        q.push(target->val);
        visited.insert(target->val);

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            if (dist == k) break;

            while (sz--) {
                int curr = q.front();
                q.pop();

                for (int nei : adj[curr]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }
            dist++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
