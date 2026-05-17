class Solution {
public:

    int ans = 0;

    void solve(TreeNode* root, vector<int>& freq) {

        freq[root->val]++;

        // leaf node
        if (root->left == NULL && root->right == NULL) {

            int odd = 0;

            for (int i = 1; i <= 9; i++) {

                if (freq[i] % 2 != 0)
                    odd++;
            }

            if (odd <= 1)
                ans++;
        }

        if (root->left)
            solve(root->left, freq);

        if (root->right)
            solve(root->right, freq);

        // backtrack
        freq[root->val]--;
        // where there is tree problem recursiona nd you have to maintainthen you to dothis another state like idnivual  soemthing on basisi ofnodes every traversla,use backtrack ,,here inorder traaversal i used intially ref++ then freq-- afgert diung left and right
    }

    int pseudoPalindromicPaths (TreeNode* root) {

        vector<int> freq(10, 0);

        solve(root, freq);

        return ans;
    }
};


// You should think about backtracking whenever:

// Rule

// You pass a shared mutable structure in recursion like:

// vector
// string
// map
// set
// frequency array
// path array

// AND you modify it during recursion.

// Then ask:

// "Will this modification affect other recursive branches?"

// If YES → you need backtracking.