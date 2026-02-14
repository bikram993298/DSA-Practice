class Solution {
public:
    
    vector<int> result;
    
    void dfs(Node* root) {
        
        if (!root)
            return;


             result.push_back(root->val);
        
        // visit all children first
        for (Node* child : root->children) {
            dfs(child);
        }
        
      
       
    }
    
    vector<int> preorder(Node* root) {
        
        dfs(root);
        
        return result;
    }
};
