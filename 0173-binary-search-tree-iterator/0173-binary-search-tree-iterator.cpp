// class BSTIterator {
// private:
//     vector<int> inorder;
//     int index = 0;

//     void traverse(TreeNode* root) {
//         if (!root) return;

//         traverse(root->left);
//         inorder.push_back(root->val);
//         traverse(root->right);
//     }

// public:
//     BSTIterator(TreeNode* root) {
//         traverse(root);
//     }

//     int next() {
//         return inorder[index++];
//     }

//     bool hasNext() {
//         return index < inorder.size();
//     }
// };
// extra o(n) space 
// here rwhat we are dong that we are itertavie inorder traversal we are doing you are inserting alll elft elemnts then last lelemnt hten if right exist push on the stack ,,has next till stakc is no tempty

class BSTIterator {
private:
    stack<TreeNode*> st;

    // Push all left nodes into stack
    void pushLeft(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    // Return next smallest
    int next() {
        TreeNode* node = st.top();
        st.pop();

        // If right subtree exists, process it
        if (node->right != NULL) {
            pushLeft(node->right);
        }

        return node->val;
    }

    // Check if more elements exist
    bool hasNext() {
        return !st.empty();
    }
};
//o(h)