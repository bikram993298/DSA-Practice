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
    bool isCompleteTree(TreeNode* root) {
          
        queue<TreeNode*> que;
        
        que.push(root);
        
        bool past = false; //kya aapne past me NULL node dekha hai ?
        // her ewe are doing level orde traversla we can see null only once if we get to see agian then false;
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            if(node == NULL) {
                past = true;
            } 
            if(node!=NULL && past==true)return false;


            // if node != null then only push because at first you got null ,,yo ignore then when push    
                if(node!=NULL){
                     que.push(node->left);
                que.push(node->right);

                }
               
            }
            return true;
        }
        
      
        
    
};