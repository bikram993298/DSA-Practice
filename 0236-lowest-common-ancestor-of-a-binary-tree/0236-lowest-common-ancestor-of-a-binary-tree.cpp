/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if(root == nullptr) return nullptr;
           // this is base case 
        if(root==p || root == q)return root;
        // we are doing postrder traversal,,if any of p ,q not present it will retrun null so that firt it encounters any left and right not null that means lca
     
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left!=nullptr && right!=nullptr){
            return root;
        }
        if(left!=nullptr)return left;
        else return right;

        
        
    }
};
// https://docs.google.com/document/d/1H_QauLqWQc5mG1qKDxrw6qPlGv7KTSOtryG8DqVbwT0/edit?tab=t.0
