// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {

//         if (!root) return true;

//         // Handle NULL children safely
//         if (root->left) {
//             int left = root->left->val;
//             if (root->val <= left) return false;
//         }

//         if (root->right) {
//             int right = root->right->val;
//             if (root->val >= right) return false;
//         }

//         // Fix: You called left subtree twice
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// };
// in thsi code i am checking for indivudaul  node left is smaller and right is biiiger 
// but in bst every left side should be smaller than node so you have pass something that tracsk its low and high value
class Solution {
public:
    bool helper(TreeNode* root, long low, long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return helper(root->left, low, root->val) &&
               helper(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
