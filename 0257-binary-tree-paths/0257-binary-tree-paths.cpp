/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
    
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    
    vector<string> result;
    
    void dfs(TreeNode* node, string path) {
        
        if (node == NULL)
            return;
        
        // add current node value
        path += to_string(node->val);
        
        // if leaf node
        if (node->left == NULL && node->right == NULL) {
            result.push_back(path);
            return;
        }
        
        // go left
        if (node->left)
            dfs(node->left, path + "->");
        
        // go right
        if (node->right)
            dfs(node->right, path + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        dfs(root, "");
        
        return result;
    }
};
