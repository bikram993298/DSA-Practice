class Solution {
public:
    vector<int> ans;
    int count = 0, maxCount = 0;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
// main idea in inonrder check preious same o rnot,,if same then count++,,count maximum,pusback it can heppen 3 3 4 4 ,,then ans 3,4 4 also shouldosuhbcak then create cindiiton maximm==coubt the a also pushback
        // Process current node
        if (prev && prev->val == root->val) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        } else if (count == maxCount) {
            ans.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
