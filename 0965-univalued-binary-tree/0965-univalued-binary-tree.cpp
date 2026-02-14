class Solution {
public:
    
    int value;
    
    bool dfs(TreeNode* root) {
        
        if (!root)
            return true;
        
        if (root->val != value)
            return false;
        
        return dfs(root->left) && dfs(root->right);
    }
    
    bool isUnivalTree(TreeNode* root) {
        
        value = root->val;
        
        return dfs(root);
    }
};
