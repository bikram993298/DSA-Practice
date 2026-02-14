class Solution {
public:
    
    vector<int> result;
    
    void dfs(Node* root) {
        
        if (!root)
            return;
        
        // visit all children first
        for (Node* child : root->children) {
            dfs(child);
        }
        
        // visit root last
        result.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        
        dfs(root);
        
        return result;
    }
};
