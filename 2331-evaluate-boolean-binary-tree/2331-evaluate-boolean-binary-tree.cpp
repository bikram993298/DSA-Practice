class Solution {
public:
    
    bool evaluateTree(TreeNode* root) {
        
        // leaf node
        if (!root->left && !root->right) {
            return root->val == 1;
        }
        
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        
        // OR
        if (root->val == 2)
            return left || right;
        
        // AND
        return left && right;
    }
};
