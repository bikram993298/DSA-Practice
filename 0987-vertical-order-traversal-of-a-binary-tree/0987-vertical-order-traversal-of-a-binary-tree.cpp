class Solution {
public:
    vector<tuple<int, int, int>> nodes;

    void dfs(TreeNode* root, int row, int col) {
        if (!root)
            return;

        // your required code start from here
        nodes.push_back({col, row, root->val});
        // your required code end here

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        // sort by col, row, value
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;

        int prevCol = INT_MIN;
        vector<int> temp;

        for (auto& [col, row, val] : nodes) {
            if (col != prevCol) {

                // push previous column into result
                if (!temp.empty()) {
                    res.push_back(temp);
                }

                temp.clear(); // start fresh column
                prevCol = col;
            }

            temp.push_back(val);
        }
        // push last column
if (!temp.empty()) {
    res.push_back(temp);
}

        return res;
    }
};