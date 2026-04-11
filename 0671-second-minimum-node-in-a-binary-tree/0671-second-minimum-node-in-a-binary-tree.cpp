class Solution {
public:
    
    long secondMin = LONG_MAX;
    int minVal;
    
    void dfs(TreeNode* root) {
        
        if (!root)
            return;
        
        if (root->val > minVal && root->val < secondMin)
            secondMin = root->val;
        
        dfs(root->left);
        dfs(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        
        minVal = root->val;
        
        dfs(root);
        
        if (secondMin == LONG_MAX)
            return -1;
        
        return secondMin;
    }
};
