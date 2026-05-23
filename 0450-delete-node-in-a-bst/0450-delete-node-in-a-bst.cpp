// class Solution {
// public:

//     // Step 1: Inorder traversal
//     void inorder(TreeNode* root, vector<int>& arr) {
//         if(root == NULL) return;

//         inorder(root->left, arr);
//         arr.push_back(root->val);
//         inorder(root->right, arr);
//     }

//     // Step 3: Build BST from sorted array
//     TreeNode* buildBST(vector<int>& arr, int left, int right) {
//         if(left > right) return NULL;

//         int mid = (left + right) / 2;

//         TreeNode* root = new TreeNode(arr[mid]);

//         root->left = buildBST(arr, left, mid - 1);
//         root->right = buildBST(arr, mid + 1, right);

//         return root;
//     }

//     TreeNode* deleteNode(TreeNode* root, int key) {

//         // Step 1: Flatten tree
//         vector<int> arr;
//         inorder(root, arr);

//         // Step 2: Remove key
//         vector<int> newArr;
//         for(int x : arr) {
//             if(x != key) newArr.push_back(x);
//         }

//         // Step 3: Rebuild BST
//         return buildBST(newArr, 0, newArr.size() - 1);
//     }
// };

class Solution {
public:

    // Function to find minimum value node (inorder successor)
    // TreeNode* findMin(TreeNode* root) {
    //     TreeNode* mini;
    //     while(root) {
    //         mini=root;
    //         root = root->left;
    //     }
    //     return mini;
    // }
    TreeNode* findMin(TreeNode* root) {

    while(root->left) {
        root = root->left;
    }

    return root;
}

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Base case
        if(root == NULL) return NULL;

        // Step 1: Traverse BST
        if(key < root->val) {
            // "Key is smaller, go left"
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            // "Key is greater, go right"
            root->right = deleteNode(root->right, key);
        }
        else {
            // "Node found, now delete it"

            // Case 1: No child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if(root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            else {
                // "Find inorder successor (smallest in right subtree)"
                TreeNode* successor = findMin(root->right);

                // "Replace value"
                root->val = successor->val;

                // "Delete the successor"
                root->right = deleteNode(root->right, successor->val);
            }
        }

        return root;
    }
};



// Case: Node has TWO children
//         5
//        / \
//       3   8
//          / \
//         6   9

// Suppose we delete 5.

// We cannot directly remove it because:

// left subtree must stay < root
// right subtree must stay > root

// So we need a replacement node.

// Why Inorder Successor?

// We choose:

// Smallest node in right subtree

// Because it is:

// greater than all left subtree values
// smallest possible greater value

// So BST remains valid.

// This Part
// TreeNode* successor = findMin(root->right);

// Find smallest node in right subtree.

// Example

// Right subtree of 5:

//       8
//      / \
//     6   9

// Minimum = 6

// So:

// successor = 6
// Next Line
// root->val = successor->val;

// We COPY successor value into current node.

// So tree becomes:

//         6
//        / \
//       3   8
//          / \
//         6   9

// Notice:

// Now there are TWO 6s.

// We only copied value,
// NOT deleted original successor yet.

// Final Line
// root->right = deleteNode(root->right, successor->val);

// Now delete duplicate 6
// from right subtree.

// Why from right subtree only?

// Because successor always exists there.

// After deletion:

//         6
//        / \
//       3   8
//            \
//             9

// Now BST is correct again.