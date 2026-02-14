// class Solution {
// public:
    
//     int rangeSumBST(TreeNode* root, int low, int high) {
        
//         if (!root)
//             return 0;
        
//         int sum = 0;
        
//         // check current node
//         if (root->val >= low && root->val <= high)
//             sum += root->val;
        
//         // check left and right subtree
//         sum += rangeSumBST(root->left, low, high);
//         sum += rangeSumBST(root->right, low, high);
        
//         return sum;
//     }
// };
// o9n)




class Solution {
public:
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if (!root)
            return 0;
        
        // skip left subtree
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        
        // skip right subtree
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        
        // include current node
        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};
//o(logn)