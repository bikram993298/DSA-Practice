class Solution {
public:

    // Step 1: Inorder traversal
    void inorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    // Step 3: Build BST from sorted array
    TreeNode* buildBST(vector<int>& arr, int left, int right) {
        if(left > right) return NULL;

        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = buildBST(arr, left, mid - 1);
        root->right = buildBST(arr, mid + 1, right);

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Step 1: Flatten tree
        vector<int> arr;
        inorder(root, arr);

        // Step 2: Remove key
        vector<int> newArr;
        for(int x : arr) {
            if(x != key) newArr.push_back(x);
        }

        // Step 3: Rebuild BST
        return buildBST(newArr, 0, newArr.size() - 1);
    }
};